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
    public static BufferedImage planet;
    public static BufferedImage asteroid;
    
    public static void init() {
        background = ImageLoader.loadImage("/images/space_background.jpg");
        planet = ImageLoader.loadImage("/images/planet.png");
        asteroid = ImageLoader.loadImage("/images/asteroid.png");
    }
    
}
