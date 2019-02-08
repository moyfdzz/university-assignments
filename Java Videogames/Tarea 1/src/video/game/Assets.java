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
    
    public static void init() {
        background = ImageLoader.loadImage("/images/sonic_background.jpg");
        player = ImageLoader.loadImage("/images/sonic.png");
    }
    
}
