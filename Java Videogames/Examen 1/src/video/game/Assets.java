/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package video.game;

import java.awt.image.BufferedImage;
import video.game.ImageLoader;

/**
 *
 * @author moisesfernandez
 */
public class Assets {
    public static BufferedImage background;
    public static BufferedImage player;
    public static BufferedImage enemy;
    public static BufferedImage lives;
    public static BufferedImage gameOver;
    public static SoundClip death;
    
    public static void init() {
        background = ImageLoader.loadImage("/images/mario_bros_background.jpg");
        player = ImageLoader.loadImage("/images/luigi.png");
        enemy = ImageLoader.loadImage("/images/goomba.png");
        lives = ImageLoader.loadImage("/images/heart.png");
        gameOver = ImageLoader.loadImage("/images/game_over.jpg");
        death = new SoundClip("/sounds/death.wav"); 
    }
    
}
