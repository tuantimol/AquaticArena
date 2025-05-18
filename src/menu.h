#ifndef _MENU__H
#define _MENU__H

#include <SDL.h>
#include <SDL_image.h>
#include "logic.h"
#include "defs.h"
#include "graphics.h"
#include <SDL_ttf.h>
#include <SDL_mixer.h>

struct Menu {
    SDL_Texture *background_menu, *option_menu, *start1, *start2, *exit1, *exit2, *highscore1, *highscore2, *back_option, *TextureTitle1,
    *turnback, *turnback_2, *pause, *pause_2, *home, *home_2, *resume, *resume_2, *TextureGameover, *gameoption, *gameoption_2,
    *Barra, *Orca, *Marlin, *Lionfish, *Shark, *TextureScore, *option, *option_2, *sound, *sound_2;
    Mix_Music *MusicMenu;
    Mix_Chunk *OverSound, *WinSound;
    int mouse_x, mouse_y, stat = 1, highscore = 0;
    SDL_Color textColor1, textColor2, textColor3, textColor4;
    TTF_Font* textTitle1, *textScore, *textGameover, *textWingame, *textScore2, *textHightScore, *textHightScoreNum;
    stringstream Titlegame1, GameoverText, scoreText;
    void init(Graphics &graphics) {
        background_menu = graphics.loadTexture("background\\back_menu.png");
        option_menu = graphics.loadTexture("background\\option_menu.png");
        start1 = graphics.loadTexture("Menu\\start_game.png");
        start2 = graphics.loadTexture("Menu\\start_game_2.png");
        exit1 = graphics.loadTexture("Menu\\exit.png");
        exit2 = graphics.loadTexture("Menu\\exit_2.png");
        highscore1 = graphics.loadTexture("Menu\\high_score.png");
        highscore2 = graphics.loadTexture("Menu\\high_score_2.png");
        back_option = graphics.loadTexture("background\\option_back.png");
        turnback = graphics.loadTexture("Menu\\turnback.png");
        turnback_2 = graphics.loadTexture("Menu\\turnback_2.png");
        pause = graphics.loadTexture("Menu\\pause.png");
        pause_2 = graphics.loadTexture("Menu\\pause_2.png");
        resume = graphics.loadTexture("Menu\\resume.png");
        resume_2 = graphics.loadTexture("Menu\\resume_2.png");
        home = graphics.loadTexture("Menu\\home.png");
        home_2 = graphics.loadTexture("Menu\\home_2.png");
        gameoption = graphics.loadTexture("Menu\\GameOption.png");
        gameoption_2 = graphics.loadTexture("Menu\\GameOption_2.png");
        MusicMenu = graphics.loadMusic("asset\\MenuMusic.mp3");
        Barra = graphics.loadTexture("image\\BarraImage.png");
        Orca = graphics.loadTexture("image\\OrcaImage.png");
        Marlin = graphics.loadTexture("image\\MarlinImage.png");
        Lionfish = graphics.loadTexture("image\\LionfishImage.png");
        sound = graphics.loadTexture("Menu\\sound.png");
        sound_2 = graphics.loadTexture("Menu\\sound_2.png");
        Shark = graphics.loadTexture("image\\SharkImage.png");
        option = graphics.loadTexture("Menu\\option.png");
        option_2 = graphics.loadTexture("Menu\\option_2.png");
        OverSound = graphics.loadSound("asset\\gameover.mp3");
        WinSound = graphics.loadSound("asset\\wingame.mp3");
        textTitle1 = graphics.loadFont(TITLE_IMG, 100);
        textScore = graphics.loadFont(SCORE_IMG, 30);
        textScore2 = graphics.loadFont(SCORE_IMG, 40);
        textGameover = graphics.loadFont(GAMEOVER_IMG, 100);
        textWingame = graphics.loadFont(GAMEOVER_IMG, 40);
        textHightScore = graphics.loadFont(TITLE_IMG, 70);
        textHightScoreNum = graphics.loadFont(TITLE_IMG, 130);
        textColor1 = {0, 250, 150, 200};            //xanh ngọc nhạt
        textColor2 = {225, 225, 125, 235};          // vàng nhạt
        textColor3 = {0, 250, 150, 0};              // xanh lá chuối
        textColor4 = {225, 0, 0, 0};                // đỏ
    }
    void drawMenu(Graphics &graphics) {
        graphics.renderTexture(background_menu, 0, 0);
        Titlegame1.str("");
        Titlegame1 << "AQUATIC ARENA";
        TextureTitle1 = graphics.loadTextTexture(Titlegame1.str().c_str(), textColor2, textTitle1);
        graphics.renderTexture(TextureTitle1, 150, 50);
        graphics.play(MusicMenu);
    }
    void drawOption(Graphics &graphics) {
        graphics.renderTexture(back_option, 0, 0);
        graphics.renderTexture(option_menu, 135, 100);
        graphics.renderTexture(Barra, SCREEN_WIDTH/2 - 100, 180);
        graphics.renderTexture(Orca, SCREEN_WIDTH/2 - 100, 230);
        graphics.renderTexture(Marlin, SCREEN_WIDTH/2 - 110, 280);
        graphics.renderTexture(Lionfish, SCREEN_WIDTH/2 - 100, 350);
        graphics.renderTexture(Shark, SCREEN_WIDTH/2 - 100, 460);
        scoreText.str("");
        scoreText << ": 100";
        TextureScore = graphics.loadTextTexture(scoreText.str().c_str(), textColor2, textScore);
        graphics.renderTexture(TextureScore, SCREEN_WIDTH/2, 180);
        scoreText.str("");
        scoreText << ": 300";
        TextureScore = graphics.loadTextTexture(scoreText.str().c_str(), textColor2, textScore);
        graphics.renderTexture(TextureScore, SCREEN_WIDTH/2, 240);
        scoreText.str("");
        scoreText << ": 500";
        TextureScore = graphics.loadTextTexture(scoreText.str().c_str(), textColor2, textScore);
        graphics.renderTexture(TextureScore, SCREEN_WIDTH/2, 290);
        scoreText.str("");
        scoreText << ": 700";
        TextureScore = graphics.loadTextTexture(scoreText.str().c_str(), textColor2, textScore);
        graphics.renderTexture(TextureScore, SCREEN_WIDTH/2, 370);
        scoreText.str("");
        scoreText << ": 900";
        TextureScore = graphics.loadTextTexture(scoreText.str().c_str(), textColor2, textScore);
        graphics.renderTexture(TextureScore, SCREEN_WIDTH/2, 460);
        graphics.play(MusicMenu);
    }
    void drawPause(Graphics &graphics) {
        graphics.renderTexture(back_option, 0, 0);
        graphics.renderTexture(option_menu, 135, 100);
        graphics.play(MusicMenu);
    }
    void drawGameover(logic &game, Graphics &graphics) {
    graphics.renderTexture(back_option, 0, 0);
    graphics.renderTexture(option_menu, 135, 100);

    GameoverText.str("");
    GameoverText << "GAME OVER";
    TextureGameover = graphics.loadTextTexture(GameoverText.str().c_str(), textColor4, textGameover);
    graphics.renderTexture(TextureGameover, 208, 180);

    GameoverText.str("");
    GameoverText << "Your Score: " << game.printScore();
    TextureGameover = graphics.loadTextTexture(GameoverText.str().c_str(), textColor2, textScore2);
    graphics.renderTexture(TextureGameover, 300, 300);

    ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> highscore;
        file.close();
    }

    if (game.printScore() > highscore) {
        highscore = game.printScore();
        ofstream outFile("highscore.txt");
        if (outFile.is_open()) {
            outFile << highscore;
            outFile.close();
        }
    }

    GameoverText.str("");
    GameoverText << "High Score: " << highscore;
    TextureGameover = graphics.loadTextTexture(GameoverText.str().c_str(), textColor1, textScore2);
    graphics.renderTexture(TextureGameover, 300, 350);
    graphics.playSound(OverSound);
}
    void drawWingame(Graphics &graphics) {
        graphics.renderTexture(back_option, 0, 0);
        graphics.renderTexture(option_menu, 135, 100);
        GameoverText.str("");
        GameoverText << "CONGRATULATION! YOU WIN!!!";
        TextureGameover = graphics.loadTextTexture(GameoverText.str().c_str(), textColor3, textWingame);
        graphics.renderTexture(TextureGameover, 200, 250);
        graphics.playSound(WinSound);
    }
    void drawHighScore(logic &game, Graphics &graphics) {
        graphics.renderTexture(back_option, 0, 0);
        graphics.renderTexture(option_menu, 135, 100);

        ifstream file("highscore.txt");
        if (file.is_open()) {
            file >> highscore;
            file.close();
        }

        GameoverText.str("");
        GameoverText << "THE HIGHSCORE IS";
        TextureGameover = graphics.loadTextTexture(GameoverText.str().c_str(), textColor2, textHightScore);
        int titleWidth, titleHeight;
        SDL_QueryTexture(TextureGameover, NULL, NULL, &titleWidth, &titleHeight);
        graphics.renderTexture(TextureGameover, (SCREEN_WIDTH - titleWidth)/2, 200);

        GameoverText.str("");
        GameoverText << highscore;
        TextureGameover = graphics.loadTextTexture(GameoverText.str().c_str(), textColor2, textHightScoreNum);
        int scoreWidth, scoreHeight;
        SDL_QueryTexture(TextureGameover, NULL, NULL, &scoreWidth, &scoreHeight);
        graphics.renderTexture(TextureGameover, (SCREEN_WIDTH - scoreWidth)/2, 300);

        graphics.play(MusicMenu);
}



    void doHighScore(logic &game, Graphics &graphics) {
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        if ( mouse_x >= 380 && mouse_x <= 460 && mouse_y >= 570 && mouse_y <= 650){
            graphics.renderTexture(turnback, 400, 570);
        }
        else graphics.renderTexture(turnback_2, 410, 570);
        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= 380 && mouse_x <= 530 && mouse_y >= 570 && mouse_y <= 650){
                    game.status = 0;
                }
                break;
            }
        }
    }
    void doMenu(logic& game, Graphics &graphics){
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        if ( mouse_x >= SCREEN_WIDTH/2 - 150 && mouse_x <= SCREEN_WIDTH/2 - 30 && mouse_y >= SCREEN_HEIGHT/2 - 130 && mouse_y <= SCREEN_HEIGHT/2 - 10){
            graphics.renderTexture(start2, SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2 - 130);
        }
        else graphics.renderTexture(start1, SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2 - 130);

        if ( mouse_x >= 482 && mouse_x <= 602 && mouse_y >= 199 && mouse_y <= 317){
            graphics.renderTexture(gameoption_2, SCREEN_WIDTH/2 + 50, SCREEN_HEIGHT/2 - 130);
        }
        else graphics.renderTexture(gameoption, SCREEN_WIDTH/2 + 50, SCREEN_HEIGHT/2 - 130);

        if ( mouse_x >= SCREEN_WIDTH/2 - 150 && mouse_x <= SCREEN_WIDTH/2 - 30 && mouse_y >= SCREEN_HEIGHT/2 + 95 && mouse_y <= SCREEN_HEIGHT/2 + 215){
            graphics.renderTexture(exit2, SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2 + 95);
        }
        else graphics.renderTexture(exit1, SCREEN_WIDTH/2 - 150, SCREEN_HEIGHT/2 + 95);

        if ( mouse_x >= 482 && mouse_x <= 602 && mouse_y >= 384 && mouse_y <= 502){
            graphics.renderTexture(highscore2, SCREEN_WIDTH/2 + 50, SCREEN_HEIGHT/2 + 95);
        }
        else graphics.renderTexture(highscore1, SCREEN_WIDTH/2 + 50, SCREEN_HEIGHT/2 + 95);

        if(stat == 1)
            graphics.renderTexture(sound_2, SCREEN_WIDTH - 60, SCREEN_HEIGHT - 60);
        else
            graphics.renderTexture(sound, SCREEN_WIDTH - 60, SCREEN_HEIGHT - 60);
        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= SCREEN_WIDTH/2 - 150 && mouse_x <= SCREEN_WIDTH/2 - 30 && mouse_y >= SCREEN_HEIGHT/2 - 130 && mouse_y <= SCREEN_HEIGHT/2 - 10){
                    Mix_HaltMusic();
                    game.status = 1;
                }
                if ( mouse_x >= 482 && mouse_x <= 602 && mouse_y >= 199 && mouse_y <= 317){
                    game.status = 2;
                }
                if ( mouse_x >= 482 && mouse_x <= 602 && mouse_y >= 384 && mouse_y <= 502){
                    game.status = 7;
                }
                if ( mouse_x >= SCREEN_WIDTH/2 - 150 && mouse_x <= SCREEN_WIDTH/2 - 30 && mouse_y >= SCREEN_HEIGHT/2 + 95 && mouse_y <= SCREEN_HEIGHT/2 + 215){
                    exit(0);
                }
                if (mouse_x >= SCREEN_WIDTH - 60 && mouse_x <= SCREEN_WIDTH - 10 && mouse_y >= SCREEN_HEIGHT - 60 && mouse_y <= SCREEN_HEIGHT - 10) {
                    stat = 1 - stat;
                }
                if(stat == 0) {
                    Mix_VolumeMusic(0);
                    Mix_VolumeChunk(game.BiteSound, 0);
                    Mix_VolumeChunk(game.ExplosionSound, 0);
                    Mix_VolumeChunk(OverSound, 0);
                    Mix_VolumeChunk(WinSound, 0);
                    Mix_VolumeChunk(game.HurtSound, 0);
                }
                else if(stat == 1) {
                    Mix_VolumeMusic(MIX_MAX_VOLUME);
                    Mix_VolumeChunk(game.BiteSound, MIX_MAX_VOLUME);
                    Mix_VolumeChunk(game.ExplosionSound, MIX_MAX_VOLUME);
                    Mix_VolumeChunk(OverSound, MIX_MAX_VOLUME);
                    Mix_VolumeChunk(WinSound, MIX_MAX_VOLUME);
                    Mix_VolumeChunk(game.HurtSound, MIX_MAX_VOLUME);
                }
                break;
            }
        }
    }
    void doOption1(logic &game, Graphics &graphics) {
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        if ( mouse_x >= 380 && mouse_x <= 460 && mouse_y >= 570 && mouse_y <= 650){
            graphics.renderTexture(turnback, 380, 570);
        }
        else graphics.renderTexture(turnback_2, 380, 570);
        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= 380 && mouse_x <= 530 && mouse_y >= 570 && mouse_y <= 650){
                    game.status = 0;
                }
                break;
            }
        }
    }
    void doOption2(logic &game, Graphics &graphics) {
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        if ( mouse_x >= 380 && mouse_x <= 460 && mouse_y >= 570 && mouse_y <= 650){
            graphics.renderTexture(turnback, 380, 570);
        }
        else graphics.renderTexture(turnback_2, 380, 570);
        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= 380 && mouse_x <= 530 && mouse_y >= 570 && mouse_y <= 650){
                    game.status = 3;
                }
                break;
            }
        }
    }
    void doPause(logic &game, Graphics &graphics) {
        SDL_Event event;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        if ( mouse_x >= SCREEN_WIDTH/2 - 100&& mouse_x <= SCREEN_WIDTH/2 - 30 && mouse_y >= 280 && mouse_y <= 350){
            graphics.renderTexture(option, SCREEN_WIDTH/2 - 100, 280);
        }
        else graphics.renderTexture(option_2, SCREEN_WIDTH/2 - 100, 280);
        if ( mouse_x >= SCREEN_WIDTH/2 + 50 && mouse_x <= SCREEN_WIDTH/2 + 120 && mouse_y >= 280 && mouse_y <= 350){
            graphics.renderTexture(resume_2, SCREEN_WIDTH/2 + 50, 280);
        }
        else graphics.renderTexture(resume, SCREEN_WIDTH/2 + 50, 280);
        if ( mouse_x >= SCREEN_WIDTH/2 - 25 && mouse_x <= SCREEN_WIDTH/2 + 45 && mouse_y >= 380 && mouse_y <= 450){
            graphics.renderTexture(home_2, SCREEN_WIDTH/2 - 25, 380);
        }
        else graphics.renderTexture(home, SCREEN_WIDTH/2 - 25, 380);
        if(stat == 1)
            graphics.renderTexture(sound_2, SCREEN_WIDTH - 60, SCREEN_HEIGHT - 60);
        else
            graphics.renderTexture(sound, SCREEN_WIDTH - 60, SCREEN_HEIGHT - 60);
        while (SDL_PollEvent(&event)){
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= SCREEN_WIDTH/2 - 100&& mouse_x <= SCREEN_WIDTH/2 - 30 && mouse_y >= 280 && mouse_y <= 350) {
                    game.status = 6;
                }
                if( mouse_x >= SCREEN_WIDTH/2 + 50 && mouse_x <= SCREEN_WIDTH/2 + 120 && mouse_y >= 280 && mouse_y <= 350) {
                    game.status = 1;
                    Mix_HaltMusic();
                }
                if ( mouse_x >= SCREEN_WIDTH/2 - 25 && mouse_x <= SCREEN_WIDTH/2 + 45 && mouse_y >= 380 && mouse_y <= 450) {
                    game.status = 0;
                }
                if (mouse_x >= SCREEN_WIDTH - 60 && mouse_x <= SCREEN_WIDTH - 10 && mouse_y >= SCREEN_HEIGHT - 60 && mouse_y <= SCREEN_HEIGHT - 10) {
                    stat = 1 - stat;
                }
                if(stat == 0) {
                    Mix_VolumeMusic(0);
                    Mix_VolumeChunk(game.BiteSound, 0);
                    Mix_VolumeChunk(game.ExplosionSound, 0);
                    Mix_VolumeChunk(OverSound, 0);
                    Mix_VolumeChunk(WinSound, 0);
                    Mix_VolumeChunk(game.HurtSound, 0);
                }
                else if(stat == 1) {
                    Mix_VolumeMusic(MIX_MAX_VOLUME);
                    Mix_VolumeChunk(game.BiteSound, MIX_MAX_VOLUME);
                    Mix_VolumeChunk(game.ExplosionSound, MIX_MAX_VOLUME);
                    Mix_VolumeChunk(OverSound, MIX_MAX_VOLUME);
                    Mix_VolumeChunk(WinSound, MIX_MAX_VOLUME);
                    Mix_VolumeChunk(game.HurtSound, MIX_MAX_VOLUME);
                }
                break;
            }
        }
    }
    void doGameoverandWin(logic &game, Graphics &graphics) {
        Mix_HaltMusic();
        SDL_Event event;
        bool quit = false;
        while (!quit){
            SDL_PollEvent(&event);
            SDL_GetMouseState(&mouse_x, &mouse_y);
            if ( mouse_x >= SCREEN_WIDTH/2 - 30&& mouse_x <= SCREEN_WIDTH/2 + 40 && mouse_y >= 450 && mouse_y <= 520){
                graphics.renderTexture(home_2, SCREEN_WIDTH/2 - 30, 450);
            }
            else graphics.renderTexture(home, SCREEN_WIDTH/2 - 30, 450);
            switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ( mouse_x >= SCREEN_WIDTH/2 - 30&& mouse_x <= SCREEN_WIDTH/2 + 40 && mouse_y >= 450 && mouse_y <= 520) {
                    game.status = 0;
                    quit = true;
                }
                break;
            }
            SDL_Delay(10);
            SDL_RenderPresent(graphics.renderer);
        }
    }
};
#endif
