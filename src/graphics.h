
#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include <vector>
#include <SDL_ttf.h>
#include<SDL_mixer.h>

struct Sprite {
    SDL_Texture* texture;
    std::vector<SDL_Rect> clips;
    int currentFrame = 0, RenderFish = 4, cntFish = 0;

    void init(SDL_Texture* _texture, int frames, const int _clips [][4]) {
        texture = _texture;
        SDL_Rect clip;
        for (int i = 0; i < frames; i++) {
            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips.push_back(clip);
        }
    }
    void tick()
    {
        cntFish++;
        if(cntFish == RenderFish)
        {
            currentFrame = (currentFrame + 1) % clips.size();
            cntFish = 0;
        }
    }

    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }
};

struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;

	void logErrorAndExit(const char* msg, const char* error)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
        SDL_Quit();
    }

	void init() {

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
        if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

        if(TTF_Init() == -1) {
            std::cout << "failed to init SDL ttf" << std::endl;
            TTF_GetError();
        }
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
            logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n",Mix_GetError());
        }

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    }
	void prepareScene(SDL_Texture * background = nullptr)
    {
        SDL_RenderClear(renderer);
        if (background != nullptr) SDL_RenderCopy( renderer, background, NULL, NULL);
    }
    void presentScene()
    {
        SDL_RenderPresent(renderer);
    }
    SDL_Texture *loadTexture(const char *filename)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL)
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

        return texture;
    }

    SDL_Texture* loadTextTexture(const std::string& text, SDL_Color textColor, TTF_Font* textfont) {
        // Kiểm tra tham số đầu vào
        if (text.empty() || textfont == nullptr) {
            std::cout << "Invalid parameters passed to loadTextTexture!" << std::endl;
            return nullptr;
        }

        // Tạo Surface từ chuỗi văn bản
        SDL_Surface* loadedSurface = TTF_RenderText_Solid(textfont, text.c_str(), textColor);
        if (loadedSurface == nullptr) {
            std::cout << "Failed to create text surface: " << TTF_GetError() << std::endl;
            return nullptr;
        }

        // Tạo Texture từ Surface
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (texture == nullptr) {
            std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(loadedSurface); // Dọn dẹp surface nếu texture không được tạo
            return nullptr;
        }

        // Dọn dẹp surface sau khi chuyển sang texture
        SDL_FreeSurface(loadedSurface);

        // Trả về texture đã tạo
        return texture;
    }



    TTF_Font* loadFont(std::string path, int fontSize){
        TTF_Font* newFont = TTF_OpenFont(path.c_str(), fontSize);
        if ( newFont == nullptr){
            std::cout << "Failed to load " << path << " font" << TTF_GetError();
        }
        return newFont;
    }

    void renderTexture(SDL_Texture *texture, int x, int y)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }
    void renderTexture2(SDL_Texture *texture, int x, int y, int health)
    {
        SDL_Rect dest;
        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

        dest.w = dest.w*health/100;
        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }
    void renderTexture3(SDL_Texture *texture, int x, int y, int score)
    {
        SDL_Rect dest;
        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

        dest.w = dest.w + 5*(score % 100);
        dest.h = dest.h + 5*(score % 100);
        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }
    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y) {
        if (!texture || !src) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                           SDL_LOG_PRIORITY_ERROR,
                "Null pointer passed to blitRect.");
            return;
        }
        SDL_Rect dest;
        dest.x = x;
        dest.y = y;
        dest.w = src->w;
        dest.h = src->h;
        SDL_RenderCopy(renderer, texture, src, &dest);
    }

        Mix_Music *loadMusic(const char* path) {
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                           SDL_LOG_PRIORITY_ERROR,
                "Could not load music from %s! SDL_mixer Error: %s", path, Mix_GetError());
        }
        return gMusic;
    }

    void play(Mix_Music *gMusic)
    {
        if (gMusic == nullptr) return;

        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic( gMusic, -1 );
        }
        else if( Mix_PausedMusic() == 1 ) {
            Mix_ResumeMusic();
        }
    }
    Mix_Chunk* loadSound(const char* path) {
    Mix_Chunk* gChunk = Mix_LoadWAV(path);
    if (gChunk == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
                       SDL_LOG_PRIORITY_ERROR,
            "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
    }
    return gChunk;
}
    void playSound(Mix_Chunk* gChunk) {
        if (gChunk != nullptr) {
            Mix_PlayChannel( -1, gChunk, 0 );
        }
    }

    void quit(Mix_Music* gMusic, Mix_Chunk* gChunk) {
    if (gMusic) {
        Mix_FreeMusic(gMusic);
    }
    if (gChunk) {
        Mix_FreeChunk(gChunk);
    }

    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    Mix_Quit();
    }


    void render(int x, int y, const Sprite& sprite) {
        const SDL_Rect* clip = sprite.getCurrentClip();
        SDL_Rect renderQuad = {x, y, clip->w, clip->h};
        SDL_RenderCopy(renderer, sprite.texture, clip, &renderQuad);
    }
    void render2(int x, int y, const Sprite& sprite, int score) {
        const SDL_Rect* clip = sprite.getCurrentClip();
        SDL_Rect rect = *clip;
        rect.w = rect.w + 5*(score / 100);
        rect.h = rect.h + 5*(score / 100);
        SDL_Rect renderQuad = {x, y, rect.w, rect.h};
        SDL_RenderCopy(renderer, sprite.texture, clip, &renderQuad);
    }
};

#endif
