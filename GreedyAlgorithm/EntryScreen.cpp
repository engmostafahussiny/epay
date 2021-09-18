#include "EntryScreen.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace System;

using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GreedyAlgorithm::EntryScreen entryScreen;
	Application::Run(% entryScreen);
}
