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
    private boolean colliding;
    private int randomDirection;
    
    /**
     * Constructor to initialize an object of the type Enemy with its attributes
     * @param x
     * @param y
     * @param width
     * @param height
     * @param game
     */
    public Enemy(int x, int y, int width, int height, Game game, int randomDirection) {
        super(x, y);
        this.width = width;
        this.height = height;
        this.game = game;      
        this.velocity = (int) ((Math.random() * (3)) + 3);
        this.colliding = false;
        this.randomDirection = randomDirection;
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

    public boolean isColliding() {
        return colliding;
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

    public void setColliding(boolean colliding) {
        this.colliding = colliding;
    }

    public int getRandomDirection() {
        return randomDirection;
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
    public boolean intersecta(Player obj) {

        return getPerimetro().intersects(obj.getPerimetro());
    }
    
    /**
     * The enemy appears with a higher velocity and in another random position
     */
    public void reappear() {
        int randomX = (int) (Math.random() * ((game.getWidth()) + 1));
        setX(randomX);
        int randomY = (int)(Math.random() * (-100));
        setY(randomY);
    }
    
    @Override
    public void tick() {    
        if (getRandomDirection() == 1) {
            setX(getX() - getVelocity());
            setY(getY() + getVelocity());
        }
        else {
            setX(getX() + getVelocity());
            setY(getY() + getVelocity());
        }

        // reset x position and y position if collision
        if (getX() >= game.getWidth()) {
            setColliding(true);
        } else if (getX() <= 0) {
            setColliding(true);
        }
        else if (getY() >= game.getHeight()) {
            setColliding(true);
        }
        
        //bot side of the window
        if (getY() + 90 >= game.getHeight()) {
            setColliding(true);
        }

    }
    
    /**
     * To render the image of the enemy
     * @param g 
     */
    @Override
    public void render(Graphics g) {
        g.drawImage(Assets.enemy, getX(), getY(), getWidth(), getHeight(), null);
    }
}
