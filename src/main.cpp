#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"
#include "menu.h"
#include "keypress.h"

using namespace std;

int SDL_main(int argc, char* argv[]){

    Graphics graphics;
    logic game;
    Input inputgame;
    Menu menu;

    graphics.init();

    SDL_Texture * background = graphics.loadTexture(BACKGROUND_IMG);

    game.InitGame(graphics);

    inputgame.init();

    menu.init(graphics);


    int mouse_x, mouse_y;
    SDL_Texture *pause, *pause_2;
    pause = graphics.loadTexture("menu\\pause.png");
    pause_2 = graphics.loadTexture("menu\\pause_2.png");
    SDL_Event event;
    while (true) {
        graphics.prepareScene();
        if(game.status == 0) {
            inputgame.SetBegin();
            game.player.setBegin();
            menu.drawMenu(graphics);
            menu.doMenu(game, graphics);
            game.setBegin();
        }
        if(game.status == 1) {
            graphics.renderTexture(background, 0, 0);
            game.drawGame(graphics);
            game.doGame(inputgame.keyboard, graphics);
            SDL_GetMouseState(&mouse_x, &mouse_y);
            if ( mouse_x >= SCREEN_WIDTH/2 && mouse_x <= SCREEN_WIDTH/2 + 30 && mouse_y >= 10 && mouse_y <= 40){
                graphics.renderTexture(pause_2, SCREEN_WIDTH/2, 10);
            }
            else graphics.renderTexture(pause, SCREEN_WIDTH/2, 10);
            while(SDL_PollEvent(&event)){
                game.doPlayer(inputgame.keyboard);
                inputgame.getInput(event);
                switch(event.type){
                    case SDL_QUIT:
                        exit(0);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if ( mouse_x >= SCREEN_WIDTH/2 && mouse_x <= SCREEN_WIDTH/2 + 30 && mouse_y >= 10 && mouse_y <= 40){
                            Mix_HaltMusic();
                            game.status = 3;
                        }
                    break;
                }
            }
        }
        if(game.status == 2) {
            menu.drawOption(graphics);
            menu.doOption1(game, graphics);
        }
        if(game.status == 3) {
            menu.drawPause(graphics);
            menu.doPause(game, graphics);
        }
        if(game.status == 4) {
            menu.drawGameover(game, graphics);
            menu.doGameoverandWin(game, graphics);
        }
        if(game.status == 5) {
            menu.drawWingame(graphics);
            menu.doGameoverandWin(game, graphics);
        }
        if(game.status == 6) {
            menu.drawOption(graphics);
            menu.doOption2(game, graphics);
        }

        if(game.status == 7) {
            menu.drawHightScore(game, graphics);
            menu.doHightScore(game, graphics);
        }

        graphics.presentScene();
        SDL_Delay(10);
    }
    return 0;
}
