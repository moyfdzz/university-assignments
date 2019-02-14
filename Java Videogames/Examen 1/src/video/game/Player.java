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
public class Player extends Item {
    
    private int width;
    private int height;
    private Game game;
    private int velocity;               // variable for the velocity of the player
    private int lives;                  // the lives of the player
    private boolean colliding;
    private int score;
    private int previousPosY;
    
    /**
     * Constructor to initialize an object of the type Player with its attributes
     * @param x
     * @param y
     * @param width
     * @param height
     * @param game
     */
    public Player(int x, int y, int width, int height, Game game) {
        super(x, y);
        this.width = width;
        this.height = height;
        this.game = game;
        this.velocity = 5;
        this.lives = (int)(Math.random() * ((5 - 3) + 1)) + 3;
        this.colliding = false;
        this.score = 0;
        this.previousPosY = y;
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
     * To get the velocity of the player
     * @return 
     */
    public int getVelocity() {
        return velocity;
    }

    /**
     * To get the number of lives of the player
     * @return 
     */
    public int getLives() {
        return lives;
    }
    
    public int getScore() {
        return score;
    }

    public boolean isColliding() {
        return colliding;
    }

    public int getPreviousPosY() {
        return previousPosY;
    }

    public void setColliding(boolean colliding) {
        this.colliding = colliding;
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
     * To set the velocity of the player
     * @param velocity 
     */
    public void setVelocity(int velocity) {
        this.velocity = velocity;
    }

    /**
     * To set the number of lives of the player
     * @param lives 
     */
    public void setLives(int lives) {
        this.lives = lives;
    }
    
    public void setScore(int score) {
        this.score = score;
    }

    public void setPreviousPosY(int previousPosY) {
        this.previousPosY = previousPosY;
    }
    
    /**
     * To get the perimeter of the rectangle of the player's image
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
    
    @Override
    public void tick() {    
        if (game.getKeyManager().Q) { // moves up + left
            setY(getY() - getVelocity());
            setX(getX() - getVelocity());
        }
        
        if (game.getKeyManager().E) { // moves up + right
            setY(getY() - getVelocity());
            setX(getX() + getVelocity());
        }
        
        if (game.getKeyManager().A) { // moves down + left
            setX(getX() - getVelocity());
            setY(getY() + getVelocity());
        }
        
        if (game.getKeyManager().D) { // moves down + right
            setX(getX() + getVelocity());
            setY(getY() + getVelocity());
        }

        if (getX() + 150 >= game.getWidth()) { // right side of the player
            setX(game.getWidth() - 150);
        } else if (getX() <= 0) { // // left side of the player
            setX(0);
        }

        if (getY() + 80 >= game.getHeight()) { // top side of the player
            setY(game.getHeight() - 80);
        } else if (getY() <= -20) { // bottom side of the player
            setY(-20);
        }
        
        //bot side of the window
        if (getY() + 150 >= game.getHeight()) {
            setY(game.getHeight() - 150);
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
     * To render the image of the player
     * @param g 
     */
    @Override
    public void render(Graphics g) {
        g.drawImage(Assets.player, getX(), getY(), getWidth(), getHeight(), null);
    }
}
