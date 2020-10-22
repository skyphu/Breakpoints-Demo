//This programme is a variation of the Camel Game created by Heath Users Group
//in 1979. The goal of the original game is to ride your camel across the desert
//while managing thirst, exhaustion and distance from the natives. In this variation,
//you must escape from Squid Knights on your rowboat. There are multiple modifications
//to the original programme throughout the game.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Global constants for randomizer maximum and minimum values.
const int MIN_MODSPEED_USER = 5,
        MAX_MODSPEED_USER = 12,
        MIN_FULLSPEED_USER = 10,
        MAX_FULLSPEED_USER = 18,
        MIN_DISTANCE_SQUID = 8,
        MAX_DISTANCE_SQUID = 16,
        MIN_EXHAUSTION = 1,
        MAX_EXHAUSTION = 3,
        MIN_RNG = 1,                     //For random events during the escape.
MAX_RNG = 40;


int main()
{
    //Game introduction.
    cout << "*********************************************************" << endl;
    cout << "* ___  _____  __  __  ____  ____     ____  __  __  _  _ *" << endl;
    cout << "*/ __)(  _  )(  )(  )(_  _)(  _ \\   (  _ \\(  )(  )( \\( )*" << endl;
    cout << "*\\__ \\ )(_)(  )(__)(  _)(_  )(_) )   )   / )(__)(  )  ( *" << endl;
    cout << "*(___/ (___/\\(______)(____)(____/   (_)\\_)(______)(_)\\_)*" << endl;
    cout << "*                                                       *" << endl;
    cout << "*********************************************************" << endl;
    cout << endl;

    cout << "Welcome to Squid Run!" << endl;
    cout << "You have stolen the sacred treasure from the Undersea Temple" << endl;
    cout << "in the Atlantic Ocean. The Squid Knights that protect this" << endl;
    cout << "temple have sworn to destroy you in the name of their god." << endl;
    cout << "Outrun (or outswim?) them on your rowboat and make it back" << endl;
    cout << "to dry land!! Be careful of thirst and exhaustion!" << endl;


    //Declaration and initialization of variables.
    bool done = false;             //Endgame variable. Sets to true when game ends.

    unsigned seed = time(0);       //Seed for the randomizer.
    srand(seed);                   //Seeding randomizer function.

    char choice;                   //Holds user menu choice.
    int thirst = 0,                //Holds user's thirst level.
    miles = 0,                 //Holds miles travelled by the user.
    exhaustion = 0,            //Holds user's level of exhaustion.
    drinks = 3,                //Holds number of drinks left in user's canteen.
    squidDistance = -20,        //Holds Squid Knights' position relative to user.
    squidMovement,             //Holds Squid Knights' movement numbers.
    userMovement,              //Holds user's movement numbers.
    randomEvent;               //Holds a randomly generated number for events.

    cout << endl << endl;
    cout << "Now row for your life!" << endl;

    while (!done) //Main programme loop.
    {
        //Main menu.
        cout << "Select an action!" << endl;
        cout << endl;
        cout << "(A) Drink from your canteen." << endl;
        cout << "(B) Row at a moderate speed." << endl;
        cout << "(C) Row at full speed." << endl;
        cout << "(D) Rest for the night." << endl;
        cout << "(E) Check your status." << endl;
        cout << "(Q) Quit." << endl;
        cout << endl;

        cin >> choice;

        if (choice == 'Q' || choice == 'q') //If user wants to quit the game.
        {
            cout << "  ___    __    __  __  ____    _____  _  _  ____  ____ " << endl;
            cout << " / __)  /__\\  (  \\/  )( ___)  (  _  )( \\/ )( ___)(  _ \\" << endl;
            cout << "( (_-. /(__)\\  )    (  )__)    )(_)(  \\  /  )__)  )   /" << endl;
            cout << " \\___/(__)(__)(_/\\/\\_)(____)  (_____)  \\/  (____)(_)\\_)" << endl;
            cout << endl;
            done = true;
        }

        else if (choice == 'E' || choice == 'e') //If user wants to check their status.
        {
            cout << "*********************************************" << endl;
            cout << "Distance rowed: " << miles << " miles." << endl;
            cout << "Drinks left: " << drinks << endl;
            cout << "The Squid Knights are " << miles - squidDistance << " miles behind you." << endl;
            cout << "*********************************************" << endl;
        }

        else if (choice == 'D' || choice == 'd') //If user wants to rest.
        {
            exhaustion = 0;
            cout << "You rest your arms for the night." << endl;
            cout << "You can feel your aching muscles thanking you for the break." << endl;
            cout << "In the back of your mind, however, the imminent threat of the" << endl;
            cout << "encroaching Squid Knights remains..." << endl;
            cout << endl;

            squidMovement = (rand() % (MAX_DISTANCE_SQUID - MIN_DISTANCE_SQUID + 1)) + MIN_DISTANCE_SQUID;
            squidDistance += squidMovement;

            if ((miles-squidDistance) <= 0 )
            {
                cout << "The Squid Knights, in their dogged persistence, have caught you." << endl;
                cout << "Your screams carry across the ocean's waves as they exact their" << endl;
                cout << "revenge upon you." << endl << endl;
                cout << "Nothing remains as evidence of your venture save for a slowly" << endl;
                cout << "fading red tinge in the water..." << endl;

                cout << "  ___    __    __  __  ____    _____  _  _  ____  ____ " << endl;
                cout << " / __)  /__\\  (  \\/  )( ___)  (  _  )( \\/ )( ___)(  _ \\" << endl;
                cout << "( (_-. /(__)\\  )    (  )__)    )(_)(  \\  /  )__)  )   /" << endl;
                cout << " \\___/(__)(__)(_/\\/\\_)(____)  (_____)  \\/  (____)(_)\\_)" << endl;
                cout << endl;

                done = true;
            }

            else if ((miles-squidDistance) > 0 && (miles - squidDistance) <= 15 )
            {
                cout << "Angry chirping noises can be heard in the distance." << endl;
                cout << "You realise in a panic that the Squid Knights are fast approaching." << endl;
                cout << "Your pulse quickens as you prepare for your next action." << endl;
                cout << endl;
            }

        }

        else if (choice == 'C' || choice == 'c') //If user wants to row at full speed.
        {
            userMovement = (rand() % (MAX_FULLSPEED_USER - MIN_FULLSPEED_USER + 1)) + MIN_FULLSPEED_USER;
            miles += userMovement;
            thirst++;
            exhaustion += (rand() % (MAX_EXHAUSTION - MIN_EXHAUSTION + 1)) + MIN_EXHAUSTION;
            squidMovement = (rand() % (MAX_DISTANCE_SQUID - MIN_DISTANCE_SQUID + 1)) + MIN_DISTANCE_SQUID;
            squidDistance += squidMovement;

            cout << "You travelled " << userMovement << " miles." << endl;

            if ((miles- squidDistance) <= 0 )
            {
                cout << "The Squid Knights, in their dogged persistence, have caught you." << endl;
                cout << "Your screams carry across the ocean's waves as they exact their" << endl;
                cout << "revenge upon you." << endl << endl;
                cout << "Nothing remains as evidence of your venture save for a slowly" << endl;
                cout << "fading red tinge in the water..." << endl;

                cout << "  ___    __    __  __  ____    _____  _  _  ____  ____ " << endl;
                cout << " / __)  /__\\  (  \\/  )( ___)  (  _  )( \\/ )( ___)(  _ \\" << endl;
                cout << "( (_-. /(__)\\  )    (  )__)    )(_)(  \\  /  )__)  )   /" << endl;
                cout << " \\___/(__)(__)(_/\\/\\_)(____)  (_____)  \\/  (____)(_)\\_)" << endl;
                cout << endl;

                done = true;
            }

            else if (exhaustion > 8 )
            {
                cout << "Your body seems to scream for respite, but you ignore it in your quest" << endl;
                cout << "to escape the Squid Knights. You can barely hold your oars anymore, but" << endl;
                cout << "you keep trying to row. Your body becomes heavier and heavier... " << endl;
                cout << "What feels like a thick fog is enveloping your mind, and you lose consciousness..." << endl;
                cout << endl;
                cout << "...In the end, your body could not fight the extreme exhaustion." << endl;
                cout << "The waves carry your corpse away into the unknown..." << endl;

                cout << "  ___    __    __  __  ____    _____  _  _  ____  ____ " << endl;
                cout << " / __)  /__\\  (  \\/  )( ___)  (  _  )( \\/ )( ___)(  _ \\" << endl;
                cout << "( (_-. /(__)\\  )    (  )__)    )(_)(  \\  /  )__)  )   /" << endl;
                cout << " \\___/(__)(__)(_/\\/\\_)(____)  (_____)  \\/  (____)(_)\\_)" << endl;
                cout << endl;

                done = true;
            }

            else if (thirst > 6)
            {
                cout << "The blazing sun scorches away at your skin. Your throat feels like" << endl;
                cout << "it's being stabbed by countless needles, but in your frantic quest to" << endl;
                cout << "escape your decapod pursuers you decide to ignore it." << endl;
                cout << "You can barely see straight and the pain is too much to bear. Slowly" << endl;
                cout << "you feel your consciousness fading until there is nothing left." << endl;
                cout << endl;
                cout << "...In the end, the thirst was too much for your frail, mortal body." << endl;
                cout << "The waves carry your corpse away into the unknown..." << endl;

                cout << "  ___    __    __  __  ____    _____  _  _  ____  ____ " << endl;
                cout << " / __)  /__\\  (  \\/  )( ___)  (  _  )( \\/ )( ___)(  _ \\" << endl;
                cout << "( (_-. /(__)\\  )    (  )__)    )(_)(  \\  /  )__)  )   /" << endl;
                cout << " \\___/(__)(__)(_/\\/\\_)(____)  (_____)  \\/  (____)(_)\\_)" << endl;
                cout << endl;

                done = true;
            }

            else if (miles >= 200)
            {
                cout << "At first, when you see it, you wonder if you're hallucinating. After" << endl;
                cout << "spending so much time at sea, you barely remember what it looks like." << endl;
                cout << "But then, as it appears to come closer and closer you realise it's not a" << endl;
                cout << "hallucination. It's real." << endl;
                cout << "You find yourself back on dry land." << endl;
                cout << "You thank the deity of your choice and wobble out of your rowboat, laughing" << endl;
                cout << "as you imagine the frustration of your squiddly pursuers when they realise" << endl;
                cout << "that they will not be able to get to you." << endl;
                cout << endl;

                cout << " _  _  _____  __  __    _    _  ____  _  _ /\\" << endl;
                cout << "( \\/ )(  _  )(  )(  )  ( \\/\\/ )(_  _)( \\( ))(" << endl;
                cout << " \\  /  )(_)(  )(__)(    )    (  _)(_  )  ( \\/" << endl;
                cout << " (__) (_____)(______)  (__/\\__)(____)(_)\\_)()" << endl;

                done = true;
            }

            else           //If no death or win conditions are cleared.
            {
                randomEvent = (rand() % (MAX_RNG - MIN_RNG + 1)) + MIN_RNG;

                if (randomEvent == 1) // 1 in 40 chance of full recovery while going full speed.
                {
                    thirst = 0;
                    exhaustion = 0;
                    drinks = 3;

                    cout << "As you row your boat, a dazzling light blinds you. You squint, and" << endl;
                    cout << "you can barely make out an amorphous shape swimming in the air." << endl;
                    cout << "With an angelic voice, the shape calls itself the Squid Matriarch, and" << endl;
                    cout << "sweetly tells you that she will bless your journey. With that, you feel" << endl;
                    cout << "your thirst and exhaustion simply melting away into a feeling of pure," << endl;
                    cout << "unadultered relief. You realise that your canteen also feels heavier." << endl;
                    cout << "You turn around to thank the creature, but she is nowhere to be seen." << endl;
                }

                if (randomEvent == 2) // 1 in 40 chance of gaining 2 additional miles.
                {
                    cout << "You feel as if the sea itself wants to aid your escape. The current seems to" << endl;
                    cout << "be pushing you in the direction of your destination." << endl;
                    miles += 2;

                    if (miles >= 200)
                    {
                        cout << "At first, when you see it, you wonder if you're hallucinating. After" << endl;
                        cout << "spending so much time at sea, you barely remember what it looks like." << endl;
                        cout << "But then, as it appears to come closer and closer you realise it's not a" << endl;
                        cout << "hallucination. It's real." << endl;
                        cout << "You find yourself back on dry land." << endl;
                        cout << "You thank the deity of your choice and wobble out of your rowboat, laughing" << endl;
                        cout << "as you imagine the frustration of your squiddly pursuers when they realise" << endl;
                        cout << "that they will not be able to get to you." << endl;
                        cout << endl;

                        cout << " _  _  _____  __  __    _    _  ____  _  _ /\\" << endl;
                        cout << "( \\/ )(  _  )(  )(  )  ( \\/\\/ )(_  _)( \\( ))(" << endl;
                        cout << " \\  /  )(_)(  )(__)(    )    (  _)(_  )  ( \\/" << endl;
                        cout << " (__) (_____)(______)  (__/\\__)(____)(_)\\_)()" << endl;

                        done = true;
                    }
                }

                if (randomEvent >2 && randomEvent <= 6) // 1 in 8 chance of losing 2 miles when going full speed.
                {
                    cout << "As the currents start pushing you backwards, you wonder if the treasure" << endl;
                    cout << "you stole is, in fact, cursed." << endl;
                    miles -= 2;

                    if ((miles- squidDistance) <= 0 )
                    {
                        cout << "The Squid Knights, in their dogged persistence, have caught you." << endl;
                        cout << "Your screams carry across the ocean's waves as they exact their" << endl;
                        cout << "revenge upon you." << endl << endl;
                        cout << "Nothing remains as evidence of your venture save for a slowly" << endl;
                        cout << "fading red tinge in the water..." << endl;

                        cout << "  ___    __    __  __  ____    _____  _  _  ____  ____ " << endl;
                        cout << " / __)  /__\\  (  \\/  )( ___)  (  _  )( \\/ )( ___)(  _ \\" << endl;
                        cout << "( (_-. /(__)\\  )    (  )__)    )(_)(  \\  /  )__)  )   /" << endl;
                        cout << " \\___/(__)(__)(_/\\/\\_)(____)  (_____)  \\/  (____)(_)\\_)" << endl;
                        cout << endl;

                        done = true;
                    }
                }

                if (thirst >= 4)
                {
                    cout << "You can feel your dry throat aching, screaming for the blessed relief of water." << endl;
                }

                if (exhaustion >=5)
                {
                    cout << "You feel your sins crawling on your back. Your arms are getting heavier, and" << endl;
                    cout << "each breath feels like it can barely provide relief to your screaming lungs." << endl;
                }

                if ((miles - squidDistance) <= 15)
                {
                    cout << "Angry chirping noises can be heard in the distance." << endl;
                    cout << "You realise in a panic that the Squid Knights are fast approaching." << endl;
                    cout << "Your pulse quickens as you prepare for your next action." << endl;
                    cout << endl;
                }
            }

        }

        else if (choice == 'B' || choice == 'b') //If user wants to row at moderate speed.
        {
            userMovement = (rand() % (MAX_MODSPEED_USER - MIN_MODSPEED_USER + 1)) + MIN_MODSPEED_USER;
            miles += userMovement;
            thirst++;
            exhaustion++;
            squidMovement = (rand() % (MAX_DISTANCE_SQUID - MIN_DISTANCE_SQUID + 1)) + MIN_DISTANCE_SQUID;
            squidDistance += squidMovement;

            cout << "You travelled " << userMovement << " miles." << endl;

            if ((miles- squidDistance) <= 0 )
            {
                cout << "The Squid Knights, in their dogged persistence, have caught you." << endl;
                cout << "Your screams carry across the ocean's waves as they exact their" << endl;
                cout << "revenge upon you." << endl << endl;
                cout << "Nothing remains as evidence of your venture save for a slowly" << endl;
                cout << "fading red tinge in the water..." << endl;

                cout << "  ___    __    __  __  ____    _____  _  _  ____  ____ " << endl;
                cout << " / __)  /__\\  (  \\/  )( ___)  (  _  )( \\/ )( ___)(  _ \\" << endl;
                cout << "( (_-. /(__)\\  )    (  )__)    )(_)(  \\  /  )__)  )   /" << endl;
                cout << " \\___/(__)(__)(_/\\/\\_)(____)  (_____)  \\/  (____)(_)\\_)" << endl;
                cout << endl;

                done = true;
            }

            else if (exhaustion > 8 )
            {
                cout << "Your body seems to scream for respite, but you ignore it in your quest" << endl;
                cout << "to escape the Squid Knights. You can barely hold your oars anymore, but" << endl;
                cout << "you keep trying to row. Your body becomes heavier and heavier... " << endl;
                cout << "What feels like a thick fog is enveloping your mind, and you lose consciousness..." << endl;
                cout << endl;
                cout << "...In the end, your body could not fight the extreme exhaustion." << endl;
                cout << "The waves carry your corpse away into the unknown..." << endl;

                cout << "  ___    __    __  __  ____    _____  _  _  ____  ____ " << endl;
                cout << " / __)  /__\\  (  \\/  )( ___)  (  _  )( \\/ )( ___)(  _ \\" << endl;
                cout << "( (_-. /(__)\\  )    (  )__)    )(_)(  \\  /  )__)  )   /" << endl;
                cout << " \\___/(__)(__)(_/\\/\\_)(____)  (_____)  \\/  (____)(_)\\_)" << endl;
                cout << endl;

                done = true;
            }

            else if (thirst > 6)
            {
                cout << "The blazing sun scorches away at your skin. Your throat feels like" << endl;
                cout << "it's being stabbed by countless needles, but in your frantic quest to" << endl;
                cout << "escape your decapod pursuers you decide to ignore it." << endl;
                cout << "You can barely see straight and the pain is too much to bear. Slowly" << endl;
                cout << "you feel your consciousness fading until there is nothing left." << endl;
                cout << endl;
                cout << "...In the end, the thirst was too much for your frail, mortal body." << endl;
                cout << "The waves carry your corpse away into the unknown..." << endl;

                cout << "  ___    __    __  __  ____    _____  _  _  ____  ____ " << endl;
                cout << " / __)  /__\\  (  \\/  )( ___)  (  _  )( \\/ )( ___)(  _ \\" << endl;
                cout << "( (_-. /(__)\\  )    (  )__)    )(_)(  \\  /  )__)  )   /" << endl;
                cout << " \\___/(__)(__)(_/\\/\\_)(____)  (_____)  \\/  (____)(_)\\_)" << endl;
                cout << endl;

                done = true;
            }

            else if (miles >= 200)
            {
                cout << "At first, when you see it, you wonder if you're hallucinating. After" << endl;
                cout << "spending so much time at sea, you barely remember what it looks like." << endl;
                cout << "But then, as it appears to come closer and closer you realise it's not a" << endl;
                cout << "hallucination. It's real." << endl;
                cout << "You find yourself back on dry land." << endl;
                cout << "You thank the deity of your choice and wobble out of your rowboat, laughing" << endl;
                cout << "as you imagine the frustration of your squiddly pursuers when they realise" << endl;
                cout << "that they will not be able to get to you." << endl;
                cout << endl;

                cout << " _  _  _____  __  __    _    _  ____  _  _ /\\" << endl;
                cout << "( \\/ )(  _  )(  )(  )  ( \\/\\/ )(_  _)( \\( ))(" << endl;
                cout << " \\  /  )(_)(  )(__)(    )    (  _)(_  )  ( \\/" << endl;
                cout << " (__) (_____)(______)  (__/\\__)(____)(_)\\_)()" << endl;

                done = true;
            }

            else           //If no death or win conditions are cleared.
            {
                randomEvent = (rand() % (MAX_RNG - MIN_RNG + 1)) + MIN_RNG;
                if (randomEvent == 1 || randomEvent == 2) // 1 in 20 chance of full recovery when going at moderate speed.
                {
                    thirst = 0;
                    exhaustion = 0;
                    drinks = 3;

                    cout << "As you row your boat, a dazzling light blinds you. You squint, and" << endl;
                    cout << "you can barely make out an amorphous shape swimming in the air." << endl;
                    cout << "With an angelic voice, the shape calls itself the Squid Matriarch, and" << endl;
                    cout << "sweetly tells you that she will bless your journey. With that, you feel" << endl;
                    cout << "your thirst and exhaustion simply melting away into a feeling of pure," << endl;
                    cout << "unadultered relief. You realise that your canteen also feels heavier." << endl;
                    cout << "You turn around to thank the creature, but she is nowhere to be seen." << endl;
                }

                if (randomEvent == 3 || randomEvent == 4) // 1 in 20 chance of gaining 2 additional miles when going at moderate speed.
                {
                    cout << "You feel as if the sea itself wants to aid your escape. The current seems to" << endl;
                    cout << "be pushing you in the direction of your destination." << endl;
                    miles += 2;

                    if (miles >= 200)
                    {
                        cout << "At first, when you see it, you wonder if you're hallucinating. After" << endl;
                        cout << "spending so much time at sea, you barely remember what it looks like." << endl;
                        cout << "But then, as it appears to come closer and closer you realise it's not a" << endl;
                        cout << "hallucination. It's real." << endl;
                        cout << "You find yourself back on dry land." << endl;
                        cout << "You thank the deity of your choice and wobble out of your rowboat, laughing" << endl;
                        cout << "as you imagine the frustration of your squiddly pursuers when they realise" << endl;
                        cout << "that they will not be able to get to you." << endl;
                        cout << endl;

                        cout << " _  _  _____  __  __    _    _  ____  _  _ /\\" << endl;
                        cout << "( \\/ )(  _  )(  )(  )  ( \\/\\/ )(_  _)( \\( ))(" << endl;
                        cout << " \\  /  )(_)(  )(__)(    )    (  _)(_  )  ( \\/" << endl;
                        cout << " (__) (_____)(______)  (__/\\__)(____)(_)\\_)()" << endl;

                        done = true;
                    }
                }

                if (randomEvent == 5 || randomEvent == 6 ) // 1 in 20 chance of losing 2 miles.
                {
                    cout << "As the currents start pushing you backwards, you wonder if the treasure" << endl;
                    cout << "you stole is, in fact, cursed." << endl;
                    miles -= 2;

                }

                if ((miles- squidDistance) <= 0 )
                {

                    cout << "The Squid Knights, in their dogged persistence, have caught you." << endl;
                    cout << "Your screams carry across the ocean's waves as they exact their" << endl;
                    cout << "revenge upon you." << endl << endl;
                    cout << "Nothing remains as evidence of your venture save for a slowly" << endl;
                    cout << "fading red tinge in the water..." << endl;

                    cout << "  ___    __    __  __  ____    _____  _  _  ____  ____ " << endl;
                    cout << " / __)  /__\\  (  \\/  )( ___)  (  _  )( \\/ )( ___)(  _ \\" << endl;
                    cout << "( (_-. /(__)\\  )    (  )__)    )(_)(  \\  /  )__)  )   /" << endl;
                    cout << " \\___/(__)(__)(_/\\/\\_)(____)  (_____)  \\/  (____)(_)\\_)" << endl;
                    cout << endl;

                    done = true;
                }


                if (thirst >= 4)
                {
                    cout << "You can feel your dry throat aching, screaming for the blessed relief of water." << endl;
                }

                if (exhaustion >=5)
                {
                    cout << "You feel your sins crawling on your back. Your arms are getting heavier, and" << endl;
                    cout << "each breath feels like it can barely provide relief to your screaming lungs." << endl;
                }

                if ((miles - squidDistance) <= 15)
                {
                    cout << "Angry chirping noises can be heard in the distance." << endl;
                    cout << "You realise in a panic that the Squid Knights are fast approaching." << endl;
                    cout << "Your pulse quickens as you prepare for your next action." << endl;
                    cout << endl;
                }
            }

        }
        else if (choice == 'A' || choice == 'a') //If user wants to drink from their canteen.
        {
            if (drinks > 0)
            {
                --drinks;
                thirst = 0;

                cout << "You take a drink from your canteen, relishing the feeling of water cooling" << endl;
                cout << "your aching throat. You feel refreshed." << endl;
            }
            else
            {
                cout << "Your expression turns to despair as you realise your canteen is empty." << endl;
            }
        }
        else         //Input validation.
        {
            cout << "You have entered an invalid choice." << endl;
            cout << "Please enter one of the choices listed in the menu." << endl;

            cin >> choice;
        }
    }

    cout << "Thanks for playing Squid Run!" << endl;

    return 0;

}