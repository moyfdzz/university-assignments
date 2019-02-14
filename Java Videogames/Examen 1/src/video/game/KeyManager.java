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
    public boolean Q;
    public boolean E;
    public boolean A;
    public boolean D;
    
    private boolean keys[];
    
    public KeyManager() {
        keys = new boolean[256];
    }
    
    @Override
    public void keyTyped(KeyEvent e) {
    }
    
    @Override
    public void keyPressed(KeyEvent e) {
        keys[e.getKeyCode()] = true;
    }
    
    @Override
    public void keyReleased(KeyEvent e) {
        keys[e.getKeyCode()] = false;
    }
    
    public void tick() {
        Q = keys[KeyEvent.VK_Q];
        E = keys[KeyEvent.VK_E];
        A = keys[KeyEvent.VK_A];
        D = keys[KeyEvent.VK_D];
    }
}
