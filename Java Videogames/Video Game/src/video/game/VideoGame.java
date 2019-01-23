/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package video.game;

/**
 *
 * @author moisesfernandez
 */
public class VideoGame {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Game g = new Game("Mario Bros", 800, 500);
        g.start();
    }
    
}
