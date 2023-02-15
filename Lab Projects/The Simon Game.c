// Name : xxxxxx xxxx
// Student Number : xxxxxxxx
// CWL Login Name : xxxxxxx
// Lab Section : xxx
// E-Mail : xxxxxxxxxxxxxxxxxxx
// Date : xxxxxxxxx
// Purpose : The Simon Game

// define constants etc.
#define LED_LOSE 13
#define LEDR 12
#define LEDY 11
#define LEDB 10
#define LEDG 9
#define LED_WIN 8

#define pb_red 7
#define pb_yellow 6
#define pb_blue 5
#define pb_green 4

// define functions prototypes
void blankall(int set);
void blink(int LED, int time);
void ingame(int turning, int arr[]);
bool checking (int turning, int arr[]);
void three_times_blink(int led_result);
void win();
void lose();
int user();

// initialization
void setup()
{
    Serial.begin(9600);

    pinMode(LED_LOSE, OUTPUT);
    pinMode(LEDR, OUTPUT);
    pinMode(LEDY, OUTPUT);
    pinMode(LEDB, OUTPUT);
    pinMode(LEDG, OUTPUT);
    pinMode(LED_WIN, OUTPUT);

    pinMode(pb_red, INPUT);
    pinMode(pb_yellow, INPUT);
    pinMode(pb_blue, INPUT);
    pinMode(pb_green, INPUT);

    randomSeed(analogRead(0));
}

// main program loop
void loop()
{
    int arr[] = {random(9,13), random(9,13), random(9,13), random(9,13), random(9,13)}; // Random array from the LED sequence.

    blinkall(500);

    ingame(1, arr);

    delay(1000);
}

void blinkall(int set) // A function that makes LED all blink.
{
    digitalWrite(LED_LOSE, HIGH);
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDY, HIGH);
    digitalWrite(LEDB, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LED_WIN, HIGH);

    delay(set);

    digitalWrite(LED_LOSE, LOW);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDY, LOW);
    digitalWrite(LEDB, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LED_WIN, LOW);

    delay(set);

    digitalWrite(LED_LOSE, HIGH);
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDY, HIGH);
    digitalWrite(LEDB, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LED_WIN, HIGH);

    delay(set);

    digitalWrite(LED_LOSE, LOW);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDY, LOW);
    digitalWrite(LEDB, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LED_WIN, LOW);

    delay(set);

    digitalWrite(LED_LOSE, HIGH);
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDY, HIGH);
    digitalWrite(LEDB, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LED_WIN, HIGH);

    delay(set);

    digitalWrite(LED_LOSE, LOW);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDY, LOW);
    digitalWrite(LEDB, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LED_WIN, LOW);

    delay(set);
}

void blink(int LED, int time) // A function that blinks one LED light for a set time.
{
    digitalWrite(LED, HIGH);
    delay(time);

    digitalWrite(LED, LOW);
    delay(time);
}

void ingame(int turning, int arr[]) // A function that makes the game play.
{
    int i;
    bool player;

    for(; true;)
    {
        for(i = 0; i < turning; i++)
        {
            blink(arr[i], 500);
        }

        player = checking(turning, arr);

        if (player == true && turning < 5)
        {
            delay(500);
            turning++;
            continue; // Going back to the start of for loop
        }

        else
        {
            break; // Getting out of the FOR LOOP
        }
    }

    if(turning == 5 && player == true)
    {
        win();
    }
    else if (player == false)
    {
        lose();
    }
}

bool checking (int turning, int arr[]) // A function that checks if the player input matches the actual sequence
{
    bool userinput = true;

    int i = 0;

    while(userinput != false && i < turning)
    {
        int pressing = user();

        if(pressing != arr[i])
        {
            userinput = false;
        }
        else if (pressing == arr[i])
        {
            i++;
            delay(300);
        }
    }

    return userinput;
}

void three_times_blink(int led_result) // A function that makes the LED blink depending on the result.
{
    for(int i = 0; i < 3; i++)
    {
        blink(led_result, 500);
    }
}

void win() // A function that blinks the LED_WIN 3 times when the player has won.
{
    int i = 0;

    three_times_blink(LED_WIN);
}

void lose() // A funciton that blinks the LED_LOSE 3 times when the player has lost.
{
    int i = 0;

    three_times_blink(LED_LOSE);
}

int user() // A function that reads the press of button
{
    int timeout = 10000; // Game will lose when user does not press button for 10 seconds (TIME-OUT FEATURE)
    int pb_color;

    for(timeout = 10000; timeout != 0; timeout--)
    {
        if (digitalRead(pb_red) == HIGH)
        {
            blink(12, 300);
            pb_color = 12;
            return pb_color;
        }
        else if (digitalRead(pb_yellow) == HIGH)
        {
            blink(11, 300);
            pb_color = 11;
            return pb_color;
        }
        else if (digitalRead(pb_blue) == HIGH)
        {
            blink(10, 300);
            pb_color = 10;
            return pb_color;
        }
        else if (digitalRead(pb_green) == HIGH)
        {
            blink(9, 300);
            pb_color = 9;
            return pb_color;
        }
        delay(1);
    }
    return 0;
}
