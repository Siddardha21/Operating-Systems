import java.util.Random;
import java.util.Scanner;

public class DiningPhil {

Philosopher[] philosophers;
Fork[] forks;
Thread[] threads;

Scanner scan;
int number;

public static void main(String[] args){

DiningPhil obj = new DiningPhil();
obj.init();
obj.startThinkingEating();
}

public void init() {
  scan=new Scanner(System.in);


  try {
    System.out.println("\nEnter the number of Philosophers");
    number=scan.nextInt();

    if(number<2){
      System.out.println("Number must be greater than one");
      return;
    }
  } catch(Exception e) {
    System.out.println("You must enter a number");
  }

  philosophers = new Philosopher[number];
  forks = new Fork[number];
  threads = new Thread[number];

  for(int i=0; i<number; i++) {
    philosophers[i]=new Philosopher(i+1);
    forks[i]=new Fork(i+1);
  }


}

public void startThinkingEating(){
  for (int i = 0; i<number; i++) {
    final int index = i;
    threads[i] = new Thread(new Runnable(){
      public void run() {
        try {
          philosophers[index].start(forks[index], forks[(index + 1) % (number)]);
        } catch (InterruptedException e) {
          e.printStackTrace();
        }
      }

    });
    threads[i].start();
  }

}

public class Fork {

private int forkid;
private boolean status;

Fork(int forkid) {
this.forkid=forkid;
this.status=true;

}
public synchronized void free() throws InterruptedException {
status = true;
}
public synchronized boolean pick(int philosopherid) throws InterruptedException {

int counter =0;
int waitUntil = new Random().nextInt(10)+5;

while(!status) {
Thread.sleep(new Random().nextInt(100)+50);

counter++;

if(counter>waitUntil){
return false;
}
}
status = false;
return true;

}
}
public class Philosopher {
private int philosopherid;
private Fork left, right;

public Philosopher(int philosopherid) {
this.philosopherid=philosopherid;
}

public void start(Fork left, Fork right) throws InterruptedException {
this.left=left;
this.right=right;

while(true){
if(new Random().nextBoolean()){
eat();
} else {
think();
}

}
}

public void think() throws InterruptedException{
System.out.println("The Philosopher " + philosopherid + " is now thinking.");
Thread.sleep(new Random().nextInt(1000) + 100);
System.out.println("The Philosopher " + philosopherid + " has stopped thinking.");
}
public void eat() throws InterruptedException {
boolean rightPick = false;
boolean leftPick = false;

System.out.println("The Philosopher " + philosopherid + " is hungry and wants to eat.");
System.out.println("The Philosopher " + philosopherid + " is picking up the ChopStick C" + left.forkid);
leftPick=left.pick(philosopherid);

if(!leftPick) {
  return;
}

System.out.println("The Philosopher " + philosopherid + " is picking up the ChopStick C" + right.forkid);
rightPick = right.pick(philosopherid);

if (!rightPick) {
  left.free();
  return;
}

System.out.println("The Philosopher " + philosopherid + " is now eating.");

Thread.sleep(new Random().nextInt(1000) +100);

left.free();
right.free();

System.out.println("The Philosopher " + philosopherid + " has stopped eating.");
}
}

}
