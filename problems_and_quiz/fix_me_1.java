
/**
 * What do we have here?
 * Something is wrong what might that be?
 * Please fix this piece of code
 */

import java.util.concurrent.Semaphore;

class Mathematician extends Thread {
    static Semaphore[] fork;
    static Semaphore getForks;
    int i, thinkCount, eatCount;

    Mathematician(int i) {
        this.i = i;
    }

    public void run() {
        while (true) {
            think();
            try {
                getForks.acquire();
                fork[i].acquire();
                fork[(i + 3) % 4].acquire();
                getForks.release();
            } catch (Exception e) {
                e.printStackTrace();
            }
            eat();
            fork[(i + 3) % 4].release();
            fork[i].release();
        }
    }

    private void think() {
        thinkCount++;
        System.out.println("think " + i + " " + thinkCount);
    }

    private void eat() {
        eatCount++;
        System.out.println("eat " + i + " " + eatCount);
    }

    public static void main(String[] args) {
        fork = new Semaphore[4];
        getForks = new Semaphore(1);
        for (int i = 0; i < 4; i++)
            fork[i] = new Semaphore(1);
        for (int i = 0; i < 4; i++)
            (new Mathematician(i)).start();
    }
}
/**
 * If you have the answer, and if you have the intrest of working with us
 * please email your answer to alexander@preferit.se and let us set up a
 * lunch meeting, where we can discuss a future employment at Preferit AB
 */
