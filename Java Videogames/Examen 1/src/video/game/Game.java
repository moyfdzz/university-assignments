/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package video.game;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;
import java.util.LinkedList;

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
    private Player player;      // variable for the player
    private KeyManager keyManager;
    private LinkedList<Enemy> enemies;
    private boolean gameOver;
    private int enemiesFallen;
    
    
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
        enemies = new LinkedList();
        this.gameOver = false;
        this.enemiesFallen = 0;
    }
    
    public int getWidth() {
        return width;
    }
    
    public int getHeight() {
        return height;
    }

    public boolean isGameOver() {
        return gameOver;
    }

    public int getEnemiesFallen() {
        return enemiesFallen;
    }

    public void setGameOver(boolean gameOver) {
        this.gameOver = gameOver;
    }

    public void setEnemiesFallen(int enemiesFallen) {
        this.enemiesFallen = enemiesFallen;
    }
    
    /**
     * initializing	the	display	window	of	the	game
     */
    private void init() {
        display = new Display(title, width, height);
        Assets.init();
        player = new Player(getWidth() / 2 - 50, getHeight() / 3, 150, 150, this);
        display.getJframe().addKeyListener(keyManager);
        
        int posX, posY, randomDirection;
        
        for (int i = 0; i <= (int)(Math.random() * ((15 - 10) + 1)) + 10; i++) {
            posX = (int)(Math.random() * ((getWidth()) + 1));
            posY = (int)(Math.random() * (-100));
            randomDirection = (int)(Math.random() * ((2 - 1) + 1)) + 1;
            enemies.add(new Enemy(posX, posY, 75, 75, this, randomDirection));
        }
    }
    
    public KeyManager getKeyManager() {
        return keyManager;
    }
    
    private void tick() {
        if (player.getLives() == 0) {
            setGameOver(true);
        }
        
        if (!isGameOver()) {
            keyManager.tick();
            player.tick();
            
            for (int i = 0; i < enemies.size(); i++) {
                enemies.get(i).tick();
                
                if (player.intersecta(enemies.get(i)) && player.getPreviousPosY() > enemies.get(i).getY()) {
                    enemies.get(i).reappear();
                    Assets.death.play();
                    player.setScore(player.getScore() + 10);
                }
                
                if (enemies.get(i).isColliding()) {
                    enemies.get(i).setColliding(false);
                    enemies.get(i).reappear();
                    setEnemiesFallen(getEnemiesFallen() + 1);
                    
                    if (getEnemiesFallen() == 10) {
                        setEnemiesFallen(0);
                        player.setLives(player.getLives() - 1);
                    }
                }
            }
        }
        
        player.setPreviousPosY(player.getY());
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
            
            g.setColor(Color.black);
            g.setFont(new Font("Serif", Font.BOLD, 20));
            
            if(!isGameOver()) {
                player.render(g);
                for (int i = 0; i < enemies.size(); i++) {
                    enemies.get(i).render(g);
                }
            
                g.drawString( "Lives : " + player.getLives() , 0 , getHeight());
                g.drawString( "Score : " + player.getScore(), getWidth() - 100, getHeight());
            }
            else {
                g.drawImage(Assets.gameOver, 0, 0, width, height, null);
            }
            
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
        int fps = 30;
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
