#include <iostream>
#include"DronesQueue.h"
#include"Drones.h"
#include<random>
#include"EarthArmy.h"
#include"AlienArmy.h"
#include"unit.h"
#include <fstream>
#include"SoModQueue.h"
#include"priQueue.h"
#include <string>
#include"EG.h"
#include"Game.h"
#include <string>
#include <vector>
#include <windows.h>
#include<mmsystem.h>
#define RESET   "\033[0m"
#define RED     "\033[31m"
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







double generate_ran(int num1, int num2)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(num1, num2); 
	
		int random_num = dis(gen);
		return  random_num;

}
// if the infectet does not get attacked by the alien it will not enter the UMl so we need to edit it 

int main()
{
	int mode;
	unit* pt = nullptr;
	int x;
	string s;
	// we used it while testing the file while working as it was easier than file
	//int arr[21] = { 7, 70, 20, 10, 50, 30, 20, 30, 3, 50, 30, 90, 2, 5, 1, 20, 40, 80, 1, 4, 0 };
	//mygame->set_arr(arr);
	Game* mygame = new Game;
	cout << " Enter 1 for interactive and 0 for silant." << endl;
	cin >> mode;
	if (mode == 0)
		mygame->set_mode(false);

	mygame->read_data();
	RandGen* rand = mygame->get_RandGen();
	rand->trans_data();
	int flag = 0;
	int etration = 100;

	////loop for the secuanse of the game////
	for (int i = 1; i <= etration; i++)
	{
		mygame->set_timestep(i);
		rand->Create_Random();
		if (mygame->is_interactive())
		{
			cout << "Current time step " << i << endl;
			mygame->print_armys();
			cout << "===================Units fighting at current timestep========================\n";
		}
	    flag = mygame->fight();
		cout << endl;
		if (mygame->is_interactive())
		{
			cout << endl<<endl;
			cout << "===================After  fighting at current timestep=====================================\n";
			mygame->print_armys();
			cout << endl;
			mygame->print_Killed();
		}
		int num_real = mygame->get_num_heal_check() + mygame->get_Aarmy()->get_num_Army() + mygame->get_Earmy()->get_num_Army() + mygame->get_num_killed()+mygame->get_ally()->get_num_su();
		int num_expected = rand->get_total_num_GEN_check();
		if (mygame->is_interactive())
		{
			cout << "=====================================================================================================\n";
			cout << "prop : " << rand->get_num_prop() << "\nnum real : " << num_real << "\nnum expected : " << num_expected << "\n";
			cout << "=====================================================================================================\n";
		}
		//if (num_real != num_expected)
		//{
		//	cout << "ERROR\n";
		//	getline(cin, s);
		//}
		if (mygame->is_interactive())
		{
			cout << "\n";
			cout << "========================================================================================================================================\n";
		}
		if (i == etration - 1)
		{
			cout << "if you want to play the audio befor the Battle end enter 1 else 0 " << endl;
			bool audio;
			cin >> audio;
			play_allAudio(audio);
		}
		//getline(cin,s);
    }
	mygame->set_left_items();
	if (mygame->is_interactive())
		cout << "\n\nnum HU Generated : " << rand->get_num_HU() << endl;
	mygame->output_file();
	if (!mygame->is_interactive())
	{
		cout << "Silent mode\nSimulation starts....\nSimulation ends, output file criated\n";
	}
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
