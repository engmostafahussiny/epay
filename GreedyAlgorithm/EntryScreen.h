#pragma once

#include "WithdrawalScreen.h"


namespace GreedyAlgorithm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EntryScreen
	/// </summary>
	public ref class EntryScreen : public System::Windows::Forms::Form
	{
	public:
		EntryScreen(void)
		{   
			ATM atm;
			
			InitializeComponent();
			if (atm.getInstance().parse_Cash_Information_units()) {
				atmoutpanel->Show();
			}
			atm.getInstance().updatecashunitstatus();
			atmoutpanel->Hide();
			if (!atm.getInstance().checkAtmHasCash()) {
				atmoutpanel->Show();
			}
			std::fstream newfile;
			newfile.open("CUinformation.txt", std::ios::in);
			if (newfile.is_open()) {
				std::string tp;
				while (getline(newfile, tp)) {  //read data from file object and put it into string.
					std::cout << tp << "\n";   //print the data of the string
				}
				newfile.close();   //close the file object.
			}
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EntryScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ administratorbtn;
	private: System::Windows::Forms::Button^ despinsebtn;
	private: System::Windows::Forms::Panel^ atmoutpanel;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EntryScreen::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->administratorbtn = (gcnew System::Windows::Forms::Button());
			this->despinsebtn = (gcnew System::Windows::Forms::Button());
			this->atmoutpanel = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->atmoutpanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(206, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(195, 196);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// administratorbtn
			// 
			this->administratorbtn->BackColor = System::Drawing::Color::Navy;
			this->administratorbtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->administratorbtn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->administratorbtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->administratorbtn->ForeColor = System::Drawing::Color::AliceBlue;
			this->administratorbtn->Location = System::Drawing::Point(12, 12);
			this->administratorbtn->Name = L"administratorbtn";
			this->administratorbtn->Size = System::Drawing::Size(120, 30);
			this->administratorbtn->TabIndex = 1;
			this->administratorbtn->Text = L"Administrator";
			this->administratorbtn->UseVisualStyleBackColor = false;
			this->administratorbtn->Click += gcnew System::EventHandler(this, &EntryScreen::administratorbtn_Click);
			// 
			// despinsebtn
			// 
			this->despinsebtn->BackColor = System::Drawing::Color::Navy;
			this->despinsebtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->despinsebtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->despinsebtn->ForeColor = System::Drawing::Color::AliceBlue;
			this->despinsebtn->Location = System::Drawing::Point(30, 250);
			this->despinsebtn->Name = L"despinsebtn";
			this->despinsebtn->Size = System::Drawing::Size(551, 103);
			this->despinsebtn->TabIndex = 2;
			this->despinsebtn->Text = L"Withdrow /Despinse";
			this->despinsebtn->UseVisualStyleBackColor = false;
			this->despinsebtn->Click += gcnew System::EventHandler(this, &EntryScreen::despinsebtn_Click);
			// 
			// atmoutpanel
			// 
			this->atmoutpanel->Controls->Add(this->textBox1);
			this->atmoutpanel->Controls->Add(this->pictureBox2);
			this->atmoutpanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->atmoutpanel->Location = System::Drawing::Point(0, 0);
			this->atmoutpanel->Name = L"atmoutpanel";
			this->atmoutpanel->Size = System::Drawing::Size(616, 377);
			this->atmoutpanel->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Navy;
			this->textBox1->Location = System::Drawing::Point(194, 250);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(236, 32);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"ATM OUT OF SERVICE";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(206, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(195, 206);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// EntryScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(616, 377);
			this->Controls->Add(this->atmoutpanel);
			this->Controls->Add(this->despinsebtn);
			this->Controls->Add(this->administratorbtn);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"EntryScreen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"EntryScreen";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->atmoutpanel->ResumeLayout(false);
			this->atmoutpanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void administratorbtn_Click(System::Object^ sender, System::EventArgs^ e) {

		
	}
	private: System::Void despinsebtn_Click(System::Object^ sender, System::EventArgs^ e) {
		WithdrawalScreen withdrawalScreen;
		withdrawalScreen.ShowDialog();
		
	}
};
}
