/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package video.game;

import java.awt.Graphics;
import java.awt.Rectangle;

/**
 *
 * @author moisesfernandez
 */
public class Enemy extends Item {
    
    private int width;
    private int height;
    private Game game;
    private int velocity;               // variable for the velocity of the enemy
    private int numberFrames;
    
    /**
     * Constructor to initialize an object of the type Enemy with its attributes
     * @param x
     * @param y
     * @param width
     * @param height
     * @param game
     */
    public Enemy(int x, int y, int width, int height, Game game) {
        super(x, y);
        this.width = width;
        this.height = height;
        this.game = game;
        this.velocity = 5;
        this.numberFrames = 0;
    }
    
    /**
     * To get the width of the window of the game
     * @return an <code>int</code> value with the width
     */
    public int getWidth() {
        return width;
    }
    
    /**
     * To get the height of the window of the game
     * @return an <code>int</code> value with the height
     */
    public int getHeight() {
        return height;
    }

    /**
     * To get the velocity of the enemy
     * @return 
     */
    public int getVelocity() {
        return velocity;
    }

    /**
     * To return the number of frames
     * @return 
     */
    public int getNumberFrames() {
        return numberFrames;
    }
    
    /**
     * To set the width of the window of the game
     * @param width 
     */
    public void setWidth(int width) {
        this.width = width;
    }
    
    /**
     * To set the height of the window of the game
     * @param height 
     */
    public void setHeight(int height) {
        this.height = height;
    }

    /**
     * To set the velocity of the enemy
     * @param velocity 
     */
    public void setVelocity(int velocity) {
        this.velocity = velocity;
    }

    /**
     * To set the number of frames
     * @param numberFrames 
     */
    public void setNumberFrames(int numberFrames) {
        this.numberFrames = numberFrames;
    }
    
    /**
     * To get the perimeter of the rectangle of the enemy's image
     * @return Rectangle
     */
    public Rectangle getPerimetro() {

        return new Rectangle(getX(), getY(), getWidth(), getHeight());
    }
    /**
     * To determine if the object is intersecting with another object
     * @param obj
     * @return Rectangle
     */
    public boolean intersecta(Enemy obj) {

        return getPerimetro().intersects(obj.getPerimetro());
    }
    
    /**
     * The enemy appears with a higher velocity and in another random position
     */
    public void reappear() {
        setVelocity(getVelocity() + 2);
        int randomX = (int) (Math.random() * getWidth() * 3 / 5);
        setX(randomX);
        int randomY = (int) (Math.random() * getHeight() + 5);
        setY(randomY);
    }
    
    public void followPlayer(int posX, int posY) {
        if (getX() <= posX) {
            setX(getX() + getVelocity());
        }
        else {
            setX(getX() - getVelocity());
        }
        
        if (getY() <= posY) {
            setY(getY() + getVelocity());
        }
        else {
            setY(getY() - getVelocity());
        }
    }
    
    @Override
    public void tick() {    
        // count the number of frames
        setNumberFrames(getNumberFrames() + 1);
        
        if (game.getMouseManager().isLeft()) {
            setX(game.getMouseManager().getX());
            setY(game.getMouseManager().getY());
        }

        if (game.getKeyManager().up) {
            setY(getY() - getVelocity());
        }
        
        if (game.getKeyManager().down) {
            setY(getY() + getVelocity());
        }
        
        if (game.getKeyManager().left) {
            setX(getX() - getVelocity());
        }
        
        if (game.getKeyManager().right) {
            setX(getX() + getVelocity());
        }

        // reset x position and y position if collision
        if (getX() + 60 >= game.getWidth()) {
            setX(game.getWidth() - 60);
        } else if (getX() <= -30) {
            setX(-30);
        }

        if (getY() + 80 >= game.getHeight()) {
            setY(game.getHeight() - 80);
        } else if (getY() <= -20) {
            setY(-20);
        }
        
        //bot side of the window
        if (getY() + 105 >= game.getHeight()) {
            setY(game.getHeight() - 105);
        }
        else if (getY() <= 0) { //top side of the window
            setY(0);
        }
        
        //right side of the window
        if (getX() + 100 >= game.getWidth()) {
            setX(game.getWidth() - 100);
        }
        else if (getX() <= 0) { //left side of the window
            setX(0);
        }
    }
    
    /**
     * To render the image of the enemy
     * @param g 
     */
    @Override
    public void render(Graphics g) {
        g.drawImage(Assets.asteroid, getX(), getY(), getWidth(), getHeight(), null);
    }
}
