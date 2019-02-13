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
public class Player extends Item {
    
    private int width;
    private int height;
    private Game game;
    private int velX; //velocity in the x axis
    private int velY; //velocity in the y axis
    private boolean isColliding; //variable to check if the player is colliding
    private int framesWhileColliding; //variable to count the frames while the player is colliding
    
    private final int maxVel;
    private final int maxFramesWhileColliding;
    
    public Player(int x, int y, int width, int height, Game game, int maxVel) {
        super(x, y);
        this.width = width;
        this.height = height;
        this.game = game;
        this.velX = 0;
        this.velY = 0;
        this.maxVel = maxVel;
        this.isColliding = false;
        this.maxFramesWhileColliding = 20;
        this.framesWhileColliding = 0;
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
     * To get the velocity in the x axis
     * @return velX
     */
    public int getVelX() {
        return velX;
    }
    
    /**
     * To get the velocity in the y axis
     * @return velY
     */
    public int getVelY() {
        return velY;
    }
    
    /**
     * To get the max velocity of the player
     * @return maxVel
     */
    public int getMaxVel() {
        return maxVel;
    }
    
    /**
     * To get the boolean of whether the player is colliding or not with the sides of the window
     * @return isColliding
     */
    public boolean getIsColliding() {
        return isColliding;
    }

    /**
     * To get the number of frames while the player is colliding with a side of the window
     * @return framesWhileColliding
     */
    public int getFramesWhileColliding() {
        return framesWhileColliding;
    }

    /**
     * To get the max number of frames while the player colliding with a side of the window
     * @return maxFramesWhileColliding
     */
    public int getMaxFramesWhileColliding() {
        return maxFramesWhileColliding;
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
     * To set the velocity in the x axis
     * @param velX 
     */
    public void setVelX(int velX) {
        this.velX = velX;
    }
    
    /**
     * To set the velocity in the y axis
     * @param velY 
     */
    public void setVelY(int velY) {
        this.velY = velY;
    }
    
    /**
     * To set if the player is colliding with a side of the window
     * @param isColliding 
     */
    public void setIsColliding(boolean isColliding) {
        this.isColliding = isColliding;
    }

    /**
     * To set the number of frames while the player is colliding with a side of the window
     * @param framesWhileColliding 
     */
    public void setFramesWhileColliding(int framesWhileColliding) {
        this.framesWhileColliding = framesWhileColliding;
    }
    
    @Override
    public void tick() {    
        // When pressed the up arrow key, the player will go up.
        if (game.getKeyManager().up) {            
            if (getVelY() * (-1) < getMaxVel()) {
                setVelY(getVelY() - 1);
            }
            
            if (getVelX() != 0) {
                if (getVelX() < 0) {
                    setVelY(getVelX());
                    setY(getY() + getVelY());
                }
                else {
                    setVelY(-getVelX());
                    setY(getY() + getVelY());
                }
            }
            
            if (getVelY() == 0) {
                setVelY(-1);
            }

            setY(getY() + getVelY());
            
            setVelX(0);
        }
        
        // When pressed the down arrow key, the player will go down.
        if (game.getKeyManager().down) {
            if (getVelY() < getMaxVel()) {
                setVelY(getVelY() + 1);
            }
            
            if (getVelX() != 0) {
                if (getVelX() < 0) {
                    setVelY(-getVelX());
                    setY(getY() + getVelY());
                }
                else {
                    setVelY(getVelX());
                    setY(getY() + getVelY());
                }
            }
            
            if (getVelY() == 0) {
                setVelY(1);
            }
             
            setY(getY() + getVelY());
            
            setVelX(0);
        }
        
        // When pressed the left arrow key, the player will go left.
        if (game.getKeyManager().left) {
            if (getVelX() * (-1) < getMaxVel()) {
                setVelX(getVelX() - 1);
            }
            
            if (getVelY() != 0) {
                if (getVelY() < 0) {
                    setVelX(getVelY());
                    setX(getX() + getVelX());
                }
                else {
                    setVelX(-getVelY());
                    setX(getX() + getVelX());
                }
            }
            
            if (getVelX() == 0) {
                setVelX(-1);
            }
            
            setX(getX() + getVelX());
            
            setVelY(0);
        }
        
        // When pressed the right arrow key, the player will go right.
        if (game.getKeyManager().right) {
            if (getVelX() < getMaxVel()) {
                setVelX(getVelX() + 1);
            }
            
            if (getVelY() != 0) {
                if (getVelY() < 0) {
                    setVelX(-getVelY());
                    setX(getX() + getVelX());
                }
                else {
                    setVelX(getVelY());
                    setX(getX() + getVelX());
                }
            }
            
            if (getVelX() == 0) {
                setVelX(1);
            }
            
            setX(getX() + getVelX());
            
            setVelY(0);
        }
        
        if (getVelX() >= getMaxVel()) {
            setVelX(getMaxVel());
        }
        
        if (getVelX() <= -getMaxVel()) {
            setVelX(-getMaxVel());
        }
        
        if (getVelY() >= getMaxVel()) {
            setVelY(getMaxVel());
        }
        
        if (getVelY() <= -getMaxVel()) {
            setVelY(-getMaxVel());
        }
        
        setX(getX() + getVelX()); //keep moving to the sides
        setY(getY() + getVelY()); //keep moving upwards or downwards
        
        //bot side of the window
        if (getY() + 90 >= game.getHeight()) {
            setVelY(-getVelY());
            setIsColliding(true);
            setFramesWhileColliding(0);
        }
        else if (getY() <= 0) { //top side of the window
            setVelY(-getVelY());
            setIsColliding(true);
            setFramesWhileColliding(0);
        }
        
        //right side of the window
        if (getX() + 90 >= game.getWidth()) {
            setVelX(-getVelX());
            setIsColliding(true);
            setFramesWhileColliding(0);
        }
        else if (getX() <= -5) { //left side of the window
            setVelX(-getVelX());
            setIsColliding(true);
            setFramesWhileColliding(0);
        }
        
        // to have the image of the player change for a short duration
        if (getIsColliding()) {
            setFramesWhileColliding(getFramesWhileColliding() + 1);
            
            if (getFramesWhileColliding() >= getMaxFramesWhileColliding()) {
                setIsColliding(false);
            }
        }
    }
    
    @Override
    public void render(Graphics g) {
        //change the image of the player in case there is a collision with a side of the window
        if(getIsColliding()) {
            g.drawImage(Assets.playerImages[1], getX(), getY(), getWidth(), getHeight(), null);
        }
        else {
            g.drawImage(Assets.playerImages[0], getX(), getY(), getWidth(), getHeight(), null);
        }
    }
}
