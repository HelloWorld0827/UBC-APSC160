// Name : xxxxxx xxxx
// Student Number : xxxxxxxx
// CWL Login Name : xxxxxxx
// Lab Section : xxx
// E-Mail : xxxxxxxxxxxxxxxxxxx
// Date : xxxxxxxxx
// Purpose : The 7-segment display that starts to display each letter in my name. (Juyong Park)


// Positions of the switch
#define LEFT LOW
#define RIGHT HIGH


// Symbolic constants for INPUT/OUTPUT pins
int const A = 11;
int const B = 10;
int const C = 7;
int const D = 8;
int const E = 9;
int const F = 12;
int const G = 13;
int const H = 6;
int const on_off_switch = 5;  // Constant for ON_OFF Switch


// Initialization
void setup(void)
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  pinMode(on_off_switch, INPUT);  // Switch setup
}


void loop(void)
{
    // Setting up the array of my name.
    char name[] = {'J','u','y','o','n','g','P','a','r','k'};

    for (int i = 0; i < 10; i++)  // Repeatedly displaying the name that was assigned in the array.
    {
        if (digitalRead(on_off_switch) == RIGHT)
        {
            letterDisp(name[i]);
            delay(1000);
            reset();
            delay(500);
        }
        else  // Comes back to the first letter of the name when the switch is turned off.
        {
            i = -1;
        }
    }
}


void letterDisp(char letter) // Takes the character, and shows it on the 7-segment display
{
    if (letter == 'J')  // Uppercase J
    {
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
        digitalWrite(H, LOW);
    }
    else if (letter == 'u')  // Lowercase u
    {
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
        digitalWrite(H, LOW);
    }
    else if (letter == 'y')  // Lowercase y
    {
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(H, LOW);
    }
    else if (letter == 'o')  // Lowercase o
    {
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
        digitalWrite(H, LOW);
    }
    else if (letter == 'n')  // Lowercase n
    {
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, HIGH);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
        digitalWrite(H, LOW);
    }
    else if (letter == 'g')  // Lowercase g
    {
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(H, LOW);
    }
    else if (letter == 'P')  // Uppercase P
    {
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(H, LOW);
    }
    else if (letter == 'a')  // Lowercase a
    {
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
        digitalWrite(H, LOW);
    }
    else if (letter == 'r')  // Lowercase r
    {
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
        digitalWrite(E, HIGH);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
        digitalWrite(H, LOW);
    }
    else if (letter == 'k')  // Lowercase k
    {
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(H, LOW);
    }
}


void reset(void)  // Reset the display to blank.
{
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
  
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(H, LOW);
}
