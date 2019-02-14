/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package video.game;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

/**
 *
 * @author moisesfernandez
 */
public class MouseManager implements MouseListener, MouseMotionListener {
    private boolean left;  // to check if left has been pushed
    private boolean right;    // to check if right has been pushed
    private int x;              // to get x position of the mouse
    private int y;              // to get y position of the mouse
    
    /**
     * The constructor of the mouse manager to initialize an object of this type
     */
    public MouseManager() {
        this.left = false;
        this.right = false;
        this.x = 0;
        this.y = 0;
    }
    
    @Override
    public void mousePressed(MouseEvent e) {
        if (e.getButton() == MouseEvent.BUTTON1) {
            setLeft(true);
            setX(e.getX() - 50);
            setY(e.getY() - 50);
        }
    }
    
    @Override
    public void mouseReleased(MouseEvent e) {
        if (e.getButton() == MouseEvent.BUTTON1) {
            setLeft(true);
            setX(e.getX() - 50);
            setY(e.getY() - 50);
        }
    }
    
    @Override
    public void mouseDragged(MouseEvent e) {
        if (e.getButton() == MouseEvent.BUTTON1) {
            setLeft(true);
            setX(e.getX() - 50);
            setY(e.getY() - 50);
        }
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseExited(MouseEvent e) {
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public void mouseMoved(MouseEvent e) {

    }   
    
    @Override
    public void mouseClicked(MouseEvent e) {
        
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public boolean isLeft() {
        return left;
    }

    public boolean isRight() {
        return right;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setLeft(boolean left) {
        this.left = left;
    }

    public void setRight(boolean right) {
        this.right = right;
    }
}
