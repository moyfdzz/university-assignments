/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package video.game;

import java.awt.Graphics;

/**
 *
 * @author moisesfernandez
 */
public abstract class Item {
    protected int x; // position x of the item
    protected int y; // position y of the item
    
    
    /**
     * Set the initial positions for the item
     * @param x
     * @param y 
     */
    public Item(int x, int y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Return the position x
     * @return x
     */
    public int getX() {
        return x;
    }

    /**
     * Return the position y
     * @return y
     */
    public int getY() {
        return y;
    }

    /**
     * Set the position x
     * @param x 
     */
    public void setX(int x) {
        this.x = x;
    }

    /**
     * Set the position y
     * @param y 
     */
    public void setY(int y) {
        this.y = y;
    }
    /**
     * The method tick updates the position of the item with each tick
     */
    public abstract void tick();
    
    /**
     * The method render paints the item
     * @param g 
     */
    public abstract void render(Graphics g);
}
