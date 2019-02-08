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
    
    private int direction;
    private int width;
    private int height;
    private Game game;
    private int velX;
    private int velY;
    
    private final int maxVel;
    
    public Player(int x, int y, int direction, int width, int height, Game game, int maxVel) {
        super(x, y);
        this.direction = direction;
        this.width = width;
        this.height = height;
        this.game = game;
        this.velX = 0;
        this.velY = 0;
        this.maxVel = maxVel;
    }
    
    public int getDirection() {
        return direction;
    }
    
    public int getWidth() {
        return width;
    }
    
    public int getHeight() {
        return height;
    }
   
    public int getVelX() {
        return velX;
    }
    
    public int getVelY() {
        return velY;
    }
    
    public int getMaxVel() {
        return maxVel;
    }
    
    public void setDirection(int direction) {
        this.direction = direction;
    }
    
    public void setWidth(int width) {
        this.width = width;
    }
    
    public void setHeight(int height) {
        this.height = height;
    }

    public void setVelX(int velX) {
        this.velX = velX;
    }

    public void setVelY(int velY) {
        this.velY = velY;
    }
    
    @Override
    public void tick() {        
        if (game.getKeyManager().up) {
            if (getVelY() * -1 < getMaxVel()) {
                
            }
        }
        if (game.getKeyManager().down) {
            setY(getY() + getVelY());
        }
        if (game.getKeyManager().left) {
            setX(getX() - getVelX());
        }
        if (game.getKeyManager().right) {
            setX(getX() + getVelX());
        }
        if (getX() + getWidth() >= game.getWidth()) {
            setX(game.getWidth() - getWidth());
        }
        else if (getX() <= -30) {
            setX(-30);
        }
        if (getY() + getHeight() >= game.getHeight()) {
            setY(game.getHeight() - getHeight());
        }
        else if (getY() <= -20) {
            setY(-20);
        }
    }
    
    @Override
    public void render(Graphics g) {
        g.drawImage(Assets.player, getX(), getY(), getWidth(), getHeight(), null);
    }
}
