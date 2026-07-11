/*
Welcome to my project now today is 08/07/2026 and in 10:44 PM, I wrote this so future readers can read my projects

Now I'm currently in grade 5, and I'm writing this to calm myself down as I like writing code

I may put this at MIT license so that others can fix me

And now this is some rules you should follow when writing code outside the license

Lastly email me or write in github issues if you spot bugs or if you want a safety mechanism , but as there's lot's of spam on the inbox, it may take a few days to find the issues

Also, I'm currently only making small updates, but small ones may come bigger and big ones may break

By the way, the dates is incorrect as I may not change it often, so check using Github or git =)

Also, if you want an acceptable update or upgrade like GUI, TUI , etc... , let me know =)

Rules:
And I may need some testers please =)

And in the community chat on github, please don't cause cyberbullying, crimes, politics, flexing, or just downright

adult content, as I'm not on the mood to do so

Rules:

Don't change the comments without permission
During the comments even when have permission don't swear or tell any misinformation others about something or someone
Don't change the typedef struct, it's very important, if you don't have permission
Don't get this wrong: return 1 equals to memory error or human failure return 2 is the others error you can or will fill in
If you want to contact me my email is phuocthanhlamnguyen@gmail.com
Use the email to tell me that there's changes , but it may takes a few days
Don't change the code to other languages , if you have no permission
Changing code also needs comments, so others can understand and learn
Flexing by changing code or other means in this repo is a big no-no
No AI or vibecoding is allowed, as I don't want any "AI-slop" or people paying tokens for this small projects
It's somewhat forced, but compile this in Linux, or UNIX like system (POSIX, MacOS), but if you're on a Windows device then just use WSL(safer but slow and room of errors) or dual-boot(more rooms for errors but dual-booting is fast in some instances and for long-term use or heavy-use, yeah use it)
On the Github repo, go to master, not main so that you found the right code to download, compile or change
If you don't want a way of email, you can call me by +84 396 656 656 (Yes, I'm Vietnamese) , but email is more preferred
Don't delete the main.c (aka. main code), even though I have git backup, but still don't dare to delete it
Done!
*/

#include <stdio.h> // Print text, and other purposes
#include <unistd.h> //For time purposes and for UNIX system call(aka. syscall)
#include <stdbool.h> //To make a loop (idk why my thoughts tell me that)
#include "util.h" // For the hexadecimal function

#define LIMIT 127 // The limit for arrays, based on the 8 bit int unsigned max, and if you're on very weak computer, urgently change this now please
#define SMALL_LIMIT 40 //Smaller limit for small chars, good for this projects
//struct variables for counting
typedef struct Counter{
    int milsec; //Milliseconds
    int sec; //Seconds
    int min; //Minutes
    int hour;//Hours
    float epochs;//Epochs(based on UNIX epochs time)
}Counter_start;
//struct for low level writing
typedef struct Char_var {
    char fail_hf[SMALL_LIMIT]; //Human failure
    char error_te[SMALL_LIMIT]; //Techical or external error
}Char_var;
//Runs in main(), as it's in C
int main(){
    //Some variables
    Counter_start epoch; //To start the struct to count
    Char_var writing = {"Human failure detected"/*For human failure*/, "External Error Detected"}; //Chars for read/write for unistd (plans from my dreams)
    char buffer[LIMIT]; //Print stuff
    char buffer_read[LIMIT]; //Read epochs.epochs
    int buffer_size; //Size of buffer to calculate
    char buffer_hex[LIMIT]; //Print hexadecimal
    //Asking the user
    printf("What is the epochs(0-86400): ");
    fflush(stdout);
    //Low level reading Linux
    int reading = read(0, buffer_read, sizeof(buffer_read)-1);
    //Prepare for if it can't read anything
    if (reading <= 0){
        //To let the user knows it's an external error
        write(1, writing.error_te, sizeof(writing.error_te));
        return 2; //Return external errors
    }
    //The null-terminate input so you may know, or ask Google for that
    buffer_read[reading] = '\0';
    //Extract and turn it into a substring we want
    sscanf(buffer_read, "%f", &epoch.epochs);
    //If epochs bigger than 1 day(possible in real life, not this time) or smaller than 0 seconds(impossible)
    if (epoch.epochs < 0.0f || epoch.epochs > 86400.0f){
        //Trace the bug from int not memory address anymore =(
        write(1, writing.fail_hf, sizeof(writing.fail_hf));
        return 1; //Return human failure
    }
    else{
        //Calculate master_ms by turning seconds => milliseconds
        long long master_ms = (long long)epoch.epochs * 1000LL;
        while (true){
            //Calculate time
            //epoch.hour = (master_ms / 3600000LL) % 24; //Calculate hours
            epoch.min = (master_ms % 3600000LL) / 60000LL; //Calculate minutes
            epoch.sec = (master_ms % 60000LL) / 1000LL; //Calculate seconds
            epoch.milsec = master_ms % 1000LL; //Calculate milliseconds
            //Assign the standard calculated seconds value back to the struct member to keep it accurate
            //epoch.epochs = (float)master_ms / 1000.0f;
            //Calculate
            int num = master_ms / 1000LL;
            //Time to count
            dectohex(num, buffer_hex);
            buffer_size = snprintf(buffer, sizeof(buffer), "\r [%02d:%02d:%02d:%03d], 0x%s"/*The hexadecimal prints in the left of this block*/, epoch.hour, epoch.min,epoch.sec, epoch.milsec, buffer_hex); //To get the buffer size of buffer
            write(1, buffer, buffer_size); //Low level way of writing in terminal, UNIX or UNIX-like system only!
            fflush(stdout);
            //Wait for 1000 mircosecond
            usleep(1000); //Low level way of writing time, UNIX or UNIX-like system only!
            //Add a milliseconds
            master_ms++;
            //Check if epochs is more or equal to a day
            if (epoch.epochs >= 864000.0f){
                //Set everything back to 0 =)
                master_ms = 0LL;
            }
        }
    }
}
