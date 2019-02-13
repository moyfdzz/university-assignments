/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package video.game;

import java.awt.Graphics;
import java.awt.image.BufferStrategy;

/**
 *
 * @author moisesfernandez
 */
public class Game implements Runnable {

    private BufferStrategy bs;	// to have several buffers when	displaying
    private Graphics g;         // to paint objects
    private Display display;	// to display in the game
    String title;															//	title	of	the	window
    private final int width;		// width of the	window
    private final int height;		// height of the window
    private Thread thread;	// thread to create the	game
    private boolean running;    // to set the game
    private Player player;
    private final KeyManager keyManager;
    
    
    /**
     * to	create	title,	width	and	height	and	set	the	game	is	still	not	running
     *
     * @param	title	to	set	the	title	of	the	window
     * @param	width	to	set	the	width	of	the	window
     * @param	height	to	set	the	height	of	the	window
     */
    public Game(String title, int width, int height) {
        this.title = title;
        this.width = width;
        this.height = height;
        running = false;
        keyManager = new KeyManager();
    }
    
    /**
     * Return the width of the window of the game
     * @return an <code>int</code> value of the width of the window of the game
     */
    public int getWidth() {
        return width;
    }
    
    /**
     * Return the height of the window of the game
     * @return an <code>int</code> value of the height of the window of the game
     */
    public int getHeight() {
        return height;
    }
    
    /**
     * initializing	the	display	window	of	the	game
     */
    private void init() {
        display = new Display(title, width, height);
        Assets.init();
        player = new Player(0, getHeight() - 100, 100, 100, this, 15);
        display.getJframe().addKeyListener(keyManager);
    }
    
    /**
     * Returns the key manager of the game
     * @return keyManager
     */
    public KeyManager getKeyManager() {
        return keyManager;
    }
    
    private void tick() {
        keyManager.tick();
        player.tick();
    }
    
    private void render() {
        // get the buffer strategy from the display
        bs = display.getCanvas().getBufferStrategy();
        /* if it is null, we define one	with 3 buffers to display images of
           the game, if	not null, then we display every	image of the game but
           after clearing the Rectanlge, getting the graphic object from the	
           buffer strategy element. show the graphic and dispose it to the trash system
         */
        if (bs == null) {
            display.getCanvas().createBufferStrategy(3);
        } else {
            g = bs.getDrawGraphics();
            g.drawImage(Assets.background, 0, 0, width, height, null);
            player.render(g);
            bs.show();
            g.dispose();
        }
        
    }
    
    public synchronized void start() {
        if(!running) {
            running = true;
            thread = new Thread(this);
            thread.start();
        }
    }
    
    public synchronized void stop() {
        if(running) {
            running = false;
            try {
                thread.join();
            } catch (InterruptedException ie) {
                ie.printStackTrace();
            }
        }
    }

    @Override
    public void run() {
        init();
        int fps = 50;
        double timeTick = 1000000000 / fps;
        double delta = 0;
        long now;
        long lastTime = System.nanoTime();
	while (running) {
            now = System.nanoTime();
            delta += (now - lastTime) / timeTick;
            lastTime = now;
            
            if (delta >= 1) {
                tick();
                render();
                delta--;
            }
        }
        stop();
    }

}
