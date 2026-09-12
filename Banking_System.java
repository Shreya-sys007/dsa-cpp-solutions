
import java.util.*;

class Banking{
    int id;
    int pin;
    float balance;
    Banking (int id, int pin, float balance){
        this.id = id;
        this.pin = pin;
        this.balance = balance;
    }
}

class Employee{
    public void printpass(float passbook[]){
        for(int i = 0; i<3; i++){
            System.out.println(i + "transaction of " + passbook[i]);
        }
    }
}
public class Main{   //can change the name Main to Banking_System
    public static void main(String[] args){
        Banking[] Users = {new Banking(101, 1234, 5500.50f), new Banking(102, 1234, 7000.00f)};
        float withdraw;
        float[] passbook = {0.0f, 0.0f, 0.0f};
        Scanner sc = new Scanner(System.in);
        int user_pin = sc.nextInt();
        int user_id = sc.nextInt();

        int flag = 0;
        for(int i = 0; i<2; i++){
            if(user_pin == Users[i].pin && user_id == Users[i].id){
                flag = 1;
                System.out.println("User no. " + i + " logged in");
                for(int j = 0; j<3; j++){
                    withdraw = sc.nextFloat();
                    if(Users[i].balance >= withdraw){
                        passbook[j] = withdraw;
                        Users[i].balance -= withdraw;
                        System.out.println("Balance: " + Users[i].balance);
                    }
                    else{
                        System.out.println("Cannot withdraw");
                    }
                }
            }
        }
        Employee p = new Employee();
        if(flag == 1){
            System.out.println("passbook: ");
            p.printpass(passbook);
        }
        else{
            System.out.println("Wrong pin or id no.");
        }
    }   
}


