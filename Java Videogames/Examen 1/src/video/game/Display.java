/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package video.game;

import java.awt.Canvas;
import java.awt.Dimension;
import java.awt.image.BufferedImage;
import javax.swing.JFrame;

/**
 *
 * @author moisesfernandez
 */
public class Display {

    public static BufferedImage player;

    private JFrame jframe;
    private Canvas canvas;
    private String title;
    private int width;
    private int height;

        /**
     * create the app and the canvas and add the canvas	to the	window	app
     */
    public void createDisplay() {
        // create the app window
        jframe = new JFrame(title);

        // set the size of the window
        jframe.setSize(width, height);

        // setting not resizable, visible and possible to close
        jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jframe.setResizable(false);
        jframe.setLocationRelativeTo(null);
        jframe.setVisible(true);

        // creating the canvas to paint and	setting	size
        canvas = new Canvas();
        canvas.setPreferredSize(new Dimension(width, height));
        canvas.setMaximumSize(new Dimension(width, height));
        canvas.setFocusable(false);

        // adding the canvas to the app window and packing to
        // get the right dimensions
        jframe.add(canvas);
        jframe.pack();
    }
    
    public JFrame getJframe() {
        return jframe;
    }

    /**
     * initializes	the	values	for	the	application	game
     *
     * @param	title	to	display	the	title	of	the	window
     * @param	width	to	set	the	width
     * @param	height	to	set	the	height
     */
    public Display(String title, int width, int height) {
        this.title = title;
        this.width = width;
        this.height = height;
        createDisplay();
    }

    /**
     * to	get	the	canvas	of	the	game
     *
     * @return	the	canvas
     */
    public Canvas getCanvas() {
        return canvas;
    }

}
