/*
Welcome to my project now today is 03/07/2026 and in 9:03 UTC, I wrote this so future readers can read my projects

Now I'm currently in grade 5, and I'm writing this to calm myself down as I like writing code

I may put this at MIT license so that others can fix me

And now this is some rules you should follow when writing code outside the license

Lastly email me if you spot bugs or if you want a safety mechanism , but as there's lot's of spam on the inbox, it may take a few days
to find

Also, I'm currently only making small updates, but big ones may come soon as what's better slow but big or fast but small, your choose it

Also, if you want an acceptable update or upgrade like GUI, TUI , etc... , let me know =)

And in the community chat on github, please don't cause cyberbullying, crimes, politics, flexing, or just downright

And I may need some testers please =)

adult content, as I'm not on the mood to do so
Rules:
1. Don't change the comments without permission
2. During the comments even when have permission don't swear or tell any misinformation others about something or someone
3. Don't change the typedef struct, it's very important, if you don't have premission
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
is fast in some instances and for long-term use or heavy-use, yeah use it)
12. On the Github repo, go to master, not main so that you found the right code to download, compile or change
13. If you don't want a way of email, you can call me by +84 396 656 656 (Yes, I'm Vietnamese) , but email is more preferred
14. Don't delete the main.c (aka. main code), even though I have git backup, but still don't dare to delete it
15. Done!*/

#include <stdio.h> // Print text, and other purposes
#include <unistd.h> //For time purposes and for UNIX system call(aka. syscall)
#define LIMIT 32767 // The limit for arrays, based on the 16 bit int signed max, and if you're on very weak computer, change this now
//All the variables
typedef struct Counter{
    int milsec; //Milliseconds
    int sec; //Seconds
    int min; //Minutes
    int hour;//Hours
    float epochs;//Epochs(based on UNIX epochs time)
}Counter_start;
//Runs in main(), as it's in C
int main(){
    //Some variables
    Counter_start epoch;
    char buffer[LIMIT];
    char buffer_read[LIMIT];
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
    sscanf(buffer_read, "%f", &epoch.epochs);
    //If epochs bigger than 1 day(possible in real life, not this time) or smaller than 0 seconds(impossible)
    if (epoch.epochs < 0 || epoch.epochs > 86400){
        //Trace the bug from int not memory address anymore =(
        printf("\a");
        char error[] = "Error Detected!\n";
        write(1, error, sizeof(error));
        return 1; //Return human failure
    }
    else{
        //Calculate master_ms by turning seconds => milliseconds
        long long master_ms = (long long)epoch.epochs * 1000LL;
        while (1){
                //Calculate time
                epoch.hour = master_ms / 3600000LL; //Calculate hours
                epoch.min = (master_ms % 3600000LL) / 60000LL; //Calculate minutes
                epoch.sec = (master_ms % 60000LL) / 1000LL; //Calculate seconds
                epoch.milsec = master_ms % 1000LL; //Calculate milliseconds
                //Assign the standard calculated seconds value back to the struct member to keep it accurate
                epoch.epochs = (float)master_ms / 1000LL;
                //Time to count
                buffer_size = snprintf(buffer, sizeof(buffer), "\r [%02d:%02d:%02d:%03d]", epoch.hour, epoch.min,epoch.sec, epoch.milsec); //To get the buffer size of buffer
                write(1, buffer, buffer_size); //Low level way of writing in terminal, UNIX or UNIX-like system only!
                fflush(stdout);
                //Wait for 1000 mircosecond
                usleep(1000); //Low level way of writing time, UNIX or UNIX-like system only!
                //Add a milliseconds
                master_ms++;
                //Check if epochs is more or equal to a day
                if (epoch.epochs >= 86400000LL){
                    //Set epoch to 0
                    printf("\a");
                    //Set everything back to 0 =)
                    epoch.epochs = 0.0f;
                    master_ms = 0LL;
                    epoch.hour = 0;
                    epoch.min = 0;
                    epoch.sec = 0;
                    epoch.milsec = 0;
                    buffer_size = snprintf(buffer, sizeof(buffer), "\r [%02d:%02d:%02d:%03d]", epoch.hour, epoch.min,epoch.sec,epoch.milsec); //To get the buffer size of buffer
                    write(1, buffer, buffer_size); //Low level way of writing in terminal, UNIX or UNIX-like system only!
                }
        }
    }
}
