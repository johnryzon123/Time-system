/*
Welcome to my project now today is 02/07/2026 and in 8:08 UTC, I wrote this so future readers can read my projects

Now I'm currently in grade 5, and I'm writing this to calm myself down as I like writing code

I may put this at MIT license so that others can fix me

And now this is some rules you should follow when writing code outside the license

Rules:
1. Don't change the comments without permission
2. During the comments even when have permission don't swear or tell any misinformation others about something or someone
3. Don't change the typedef struct, it's very important
4. Don't get this wrong:
return 1 equals to memory error or human failure
return 2 is the others error you can or will fill in
5. If you want to contact me my email is phuocthanhlamnguyen@gmail.com
6. Use the email to tell me that there's changes , but it may takes a few days
7. Don't change the code to other languages , if you have no permission
8. Changing code also needs comments, so others can understand and learn
9. Flexing by changing code or other means in this repo is a big no-no
10. No AI or little is allowed, as I don't want any "AI-slop" or people paying tokens for this small projects
11. Done!*/

#include <stdio.h> // Print and asked
#include <unistd.h> //For time purposes
//All the variables
typedef struct Counter{
    int sec; //Seconds
    int min; //Minutes
    int hour;//Hours
    int epochs;//Epochs(based on UNIX epochs time)
}Counter_start;
//Runs in main(), as it's in C
int main(){
    Counter_start epoch;
    //Asking the user
    printf("What is the epochs(0-86400): ");
    scanf("%d", &epoch.epochs);
    //If epochs bigger than 1 day(possible in real life, not this time) or smaller than 0 seconds(impossible)
    if (epoch.epochs < 0 || epoch.epochs > 86400){
        //Trace the bug to a memory address
        printf("Error on %p\n", epoch.epochs);
        return 1; //Return human failure
    }
    else{
        while (1){
                //Calculate time
                epoch.hour = epoch.epochs / 3600;
                epoch.min = (epoch.epochs % 3600) / 60;
                epoch.sec = epoch.epochs % 60;
                //Time
                printf("\r[%d:%d:%d]", epoch.hour, epoch.min,epoch.sec);
                fflush(stdout);
                //Wait 1 second
                sleep(1);
                //Add 1 more in epoch
                epoch.epochs++;
                //Check if epochs is more or equal to 86400
                if (epoch.epochs >= 86400){
                    //Set epoch to 0
                    epoch.epochs = 0;
                }
        }
    }
}
