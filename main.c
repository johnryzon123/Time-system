/*
Welcome to my project now today is 03/07/2026 and in 9:03 UTC, I wrote this so future readers can read my projects

Now I'm currently in grade 5, and I'm writing this to calm myself down as I like writing code

I may put this at MIT license so that others can fix me

And now this is some rules you should follow when writing code outside the license

Lastly email me if you spot bugs or if you want a safety mechanism , but as there's lot's of spam on the inbox, it may take a few days
to find

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
11. It's somewhat forced, but compile this in Linux, or UNIX like system (POSIX, MacOS), but if you're on a Windows
device than just use WSL(safer but slow and room of errors) or dual-boot(more rooms for errors but dual-booting
is fast in some instances and for long-term use, yeah use it)
12. Done!*/

#include <stdio.h> // Print text, and other purposes
#include <unistd.h> //For time purposes and for UNIX syscall
//All the variables
typedef struct Counter{
    int sec; //Seconds
    int min; //Minutes
    int hour;//Hours
    int epochs;//Epochs(based on UNIX epochs time)
}Counter_start;
//Runs in main(), as it's in C
int main(){
    //Some variables
    Counter_start epoch;
    char buffer[100];
    char buffer_read[100];
    int buffer_size;
    //Asking the user
    printf("What is the epochs(0-86400): ");
    fflush(stdout);
    //Low level reading Linux
    int reading = read(0, buffer_read, sizeof(buffer_read)-1);
    //Prepare for if it can't read any thing
    if (reading <= 0){
        return 2; //Return external errors
    }
    //The null-terminate input so you may know, or ask Google for that
    buffer_read[reading] = '\0';
    //Extract and turn it into a substring we want
    sscanf(buffer_read, "%d", &epoch.epochs);
    //If epochs bigger than 1 day(possible in real life, not this time) or smaller than 0 seconds(impossible)
    if (epoch.epochs < 0 || epoch.epochs > 86400){
        //Trace the bug from int not memory address anymore =(
        printf("Error on %d\n", epoch.epochs);
        return 1; //Return human failure
    }
    else{
        while (1){
                //Calculate time
                epoch.hour = epoch.epochs / 3600;
                epoch.min = (epoch.epochs % 3600) / 60;
                epoch.sec = epoch.epochs % 60;
                //Time
                buffer_size = snprintf(buffer, sizeof(buffer), "\r [%02d:%02d:%02d]", epoch.hour, epoch.min,epoch.sec);
                write(1, buffer, buffer_size); //Low level way of writing in terminal, UNIX or UNIX-like system only!
                fflush(stdout);
                //Wait 1 second
                sleep(1); //Low level way of writing time, UNIX or UNIX-like system only!
                //Add 1 more in epoch
                epoch.epochs++;
                //Check if epochs is more or equal to 86400
                if (epoch.epochs >= 86400){
                    //Set epoch to 0
                    epoch.epochs = 0;
                    buffer_size = snprintf(buffer, sizeof(buffer), "\r [%02d:%02d:%02d]", epoch.hour, epoch.min,epoch.sec);
                    write(1, buffer, buffer_size); //Low level way of writing in terminal, UNIX or UNIX-like system only!
                }
        }
    }
}
