#include <iostream>
#include <string>
#include"Game.h"
#include <vector>  //for audio only and not used as data structure
#include <windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

void displayWord(const std::string& word) {
	std::cout << word << " ";
}

// Function to play audio using WinMM
void playAudio() {
	// Open the audio file
	PlaySound(TEXT("fight.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void play_allAudio(bool x);

// if the infectet does not get attacked by the alien it will not enter the UMl so we need to edit it 

int main()
{

	string soldier = R"(
                                                                     _________________________          _____
                                                                    |                         \          \ U \__      _____
                                                                    |    Alien Invasion        \__________\   \/_______\___\_____________
                                                                    |                          /           /_/   .....................  `-.
                                                                    |_________________________/            `-----------,----,--------------'
                                                                                                                     _/____/
                                                                       |\                |\                |\                |\
                                                                       || .---.          || .---.          || .---.          || .---.
                                                                       ||/_____\         ||/_____\         ||/_____\         ||/_____\
                                                                       ||( '.' )         ||( '.' )         ||( '.' )         ||( '.' )
                                                                       || \_-_/_         || \_-_/_         || \_-_/_         || \_-_/_
                                                                       :-"`'V'//-.       :-"`'V'//-.       :-"`'V'//-.       :-"`'V'//-.
                                                                      / ,   |// , `\    / ,   |// , `\    / ,   |// , `\    / ,   |// , `\
                                                                     / /|Ll //Ll|| |   / /|Ll //Ll|| |   / /|Ll //Ll|| |   / /|Ll //Ll|| |
                                                                    /_/||__//   || |  /_/||__//   || |  /_/||__//   || |  /_/||__//   || |
                                                                    \ \/---|[]==|| |  \ \/---|[]==|| |  \ \/---|[]==|| |  \ \/---|[]==|| |
                                                                     \/\__/ |   \| |   \/\__/ |   \| |   \/\__/ |   \| |   \/\__/ |   \| |
                                                                     /\|_   | Ll_\ |   /|/_   | Ll_\ |   /|/_   | Ll_\ |   /|/_   | Ll_\ |
                                                                     `--|`^"""^`||_|   `--|`^"""^`||_|   `--|`^"""^`||_|   `--|`^"""^`||_|
                                                                        |   |   ||/       |   |   ||/       |   |   ||/       |   |   ||/
                                                                        |   |   |         |   |   |         |   |   |         |   |   |
                                                                        |   |   |         |   |   |         |   |   |         |   |   |                             
                                                                        |   |   |         |   |   |         |   |   |         |   |   |
                                                                        L___l___J         L___l___J         L___l___J         L___l___J
                                                                         |_ | _|           |_ | _|           |_ | _|           |_ | _|
                                                                        (___|___)         (___|___)         (___|___)         (___|___)
                                                                         ^^^ ^^^           ^^^ ^^^           ^^^ ^^^           ^^^ ^^^  
                                                                                   _-o#&&*''''?d:>b\_
                                                                                _o/"`''  '',, dMF9MMMMMHo_
                                                                             .o&#'        `"MbHMMMMMMMMMMMHo.
                                                                           .o"" '         vodM*$&&HMMMMMMMMMM?.
                                                                          ,'              $M&ood,~'`(&##MMMMMMH\
                                                                         /               ,MMMMMMM#b?#bobMMMMHMMML
                                                                        &              ?MMMMMMMMMMMMMMMMM7MMM$R*Hk
                                                                       ?$.            :MMMMMMMMMMMMMMMMMMM/HMMM|`*L
                                                                      |               |MMMMMMMMMMMMMMMMMMMMbMH'   T,
                                                                      $H#:            `*MMMMMMMMMMMMMMMMMMMMb#}'  `?
                                                                      ]MMH#             ""*""""*#MMMMMMMMMMMMM'    -
                                                                      MMMMMb_                   |MMMMMMMMMMMP'     :
                                                                      HMMMMMMMHo                 `MMMMMMMMMT       .
                                                                      ?MMMMMMMMP                  9MMMMMMMM}       -
                                                                      -?MMMMMMM                  |MMMMMMMMM?,d-    '
                                                                       :|MMMMMM-                 `MMMMMMMT .M|.   :
                                                                        .9MMM[                    &MMMMM*' `'    .
                                                                         :9MMk                    `MMM#"        -
                                                                           &M}                     `          .-
                                                                            `&.                             .
                                                                              `~,   .                     ./
                                                                                  . _                  .-
                                                                                    '`--._,dd###pp=""'
                                                                                     .-""""-.       .-""""-.
                                                                                    /        \     /        \
                                                                                   /_        _\   /_        _\
                                                                                  // \      / \\ // \      / \\
                                                                                  |\__\    /__/| |\__\    /__/|
                                                                                   \    ||    /   \    ||    /
                                                                                    \        /     \        /
                                                                                     \  __  /       \  __  /
                                                                             .-""""-. '.__.'.-""""-. '.__.'.-""""-.
                                                                            /        \ |  |/        \ |  |/        \
                                                                           /_        _\|  /_        _\|  /_        _\
                                                                          // \      / \\ // \      / \\ // \      / \\
                                                                          |\__\    /__/| |\__\    /__/| |\__\    /__/|
                                                                           \    ||    /   \    ||    /   \    ||    /
                                                                            \        /     \        /     \        /
                                                                             \  __  /       \  __  /       \  __  /
                                                                              '.__.'         '.__.'         '.__.'
                                                                               |  |           |  |           |  |
                                                                               |  |           |  |           |  |


)";

	cout << soldier;
	Sleep(2000);


	Game* mygame = new Game;
    mygame->simulate();
    
    
    cout << "if you want to play the audio the for Battle enter 1 else 0 " << endl;
    bool audio;
    cin >> audio;
    play_allAudio(audio);



	delete mygame;
	mygame = nullptr;
	return 0;
}












void play_allAudio(bool x)
{
	if(x)
	{
		// Example script with words and timing (in milliseconds)
		std::vector<std::pair<std::string, int>> script = {
			//{"hello", 0},
			{"Commander: There's no point standing around ", 1000}, // Display "world" after 1 second
			{"You'll only be showered by more boulders ", 2000} ,
			{"Ready your horses on the double!\n", 4000},
			{"Soldier: Be honest, are all of us riding to our death?\n", 8000},
			{"Commander: Yes, we are...\n", 13000},
			{"Soldier: And since we're dying anyway, you're saying that it's better? if we at least die fighting?\n", 15000},
			{"Commander: I am...\n", 22000},
			{"Soldier: But wait, if we'll die anyway, then who cares what we do? We could just disobey your orders. And it wouldn't mean a thing, would it?\n", 24000},
			{"Commander: Yes, you're precisely right.................\n", 33000},
			{"Everything that you thought had meaning, every hope, dream, or moment of happiness.\n", 35000},
			{"None of it matters as you lie bleeding out on the battlefield.\n", 42000},
			{"None of it changes what a speeding rock does to a body.\n", 45500},
			{"We all die. But does that mean our lives are meaningless.\n", 49000},
			{"Does that mean that there was no point in our being born.\n", 55000},
			{"Would you say that of our slain comrades. What about their lives, were they meaningless.\n", 59000},
			{"They were not, their memory serves as an example to us all! The courageous fallen, the anguished fallen, their lives have meaning because we, the living refuse to forget them and as we ride to certain death, ", 69000},
			{"we trust our successors to do the same for us! Because my soldiers do not buckle or yield when faced with the cruelty of this world!\n", 83000},
			{"MY SOLDIERS PUSH FORWARD!\n", 92000},
			{"MY SOLDIERS SCREAM OUT!\n", 94000},
			{"MY SOLDIERS RAGE!\n", 97000},
			//{"standing ", 1300},
			//{"around ", 1400} ,// Display "!" after 2 seconds
		};

		// Play audio
		playAudio();

		// Display words at specified timings
		auto start_time = GetTickCount64();
		for (const auto& entry : script) {
			// Calculate elapsed time
			auto elapsed_time = GetTickCount64() - start_time;
			auto elapsed_ms = static_cast<int>(elapsed_time);

			// Wait until it's time to display the word
			if (elapsed_ms < entry.second) {
				Sleep(entry.second - elapsed_ms);
			}

			// Display the word
			displayWord(entry.first);
		}
		std::cout << std::endl;

		// Wait for audio to finish playing
		Sleep(6000); // Adjust this delay according to the length of your audio file
		cout << "=============================="<< RED<<"ATTAAAAAAAAAAACK"<<RESET<<"========================================\n";
		Sleep(2000);
	}
}
