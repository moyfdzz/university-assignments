/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package video.game;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

/**
 *
 * @author moisesfernandez
 */
public class KeyManager implements KeyListener{
    public boolean up;
    public boolean down;
    public boolean left;
    public boolean right;
    
    private boolean keys[];
    private boolean movementArrowKeys[]; //array of booleans to check when the arrow keys are pressed
    
    public KeyManager() {
        keys = new boolean[256];
        movementArrowKeys = new boolean[4];
    }
    
    @Override
    public void keyTyped(KeyEvent e) {
    }
    
    @Override
    public void keyPressed(KeyEvent e) {
        keys[e.getKeyCode()] = false;
    }
    
    @Override
    public void keyReleased(KeyEvent e) {
        keys[e.getKeyCode()] = true;
    }
    
    public void tick() {    
        // the case when the up arrow key is pressed
        if (keys[KeyEvent.VK_UP]) {
            if (!movementArrowKeys[0]) {
                up = true;
                movementArrowKeys[0] = true;
            }
            else {
                up = false;
            }
        }
        else {
            movementArrowKeys[0] = false;
            
            up = keys[KeyEvent.VK_UP];
        }
        
        // the case when the left arrow key is pressed
        if (keys[KeyEvent.VK_LEFT]) {
            if (!movementArrowKeys[1]) {
                left = true;
                movementArrowKeys[1] = true;
            }
            else {
                left = false;
            }
        }
        else {
            movementArrowKeys[1] = false;
        }
        
        // the case when the down arrow key is pressed
        if (keys[KeyEvent.VK_DOWN]) {
            if (!movementArrowKeys[2]) {
                down = true;
                movementArrowKeys[2] = true;
            }
            else {
                down = false;
            }
        }
        else {
            movementArrowKeys[2] = false;
        }
        
        // the case when the right arrow key is pressed
        if (keys[KeyEvent.VK_RIGHT]) {
            if (!movementArrowKeys[3]) {
                right = true;
                movementArrowKeys[3] = true;
            }
            else {
                right = false;
            }
        }
        else {
            movementArrowKeys[3] = false;
        }
        
        
    }
}
