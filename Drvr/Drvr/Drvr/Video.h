#pragma once

namespace Drvr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Video
	/// </summary>
	public ref class Video : public System::Windows::Forms::Form
	{
	public:
		Video(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Video()
		{
			if (components)
			{
				delete components;
			}
		}
	private: AxWMPLib::AxWindowsMediaPlayer^  axWindowsMediaPlayer1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Video::typeid));
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->BeginInit();
			this->SuspendLayout();
			// 
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(65, 47);
			this->axWindowsMediaPlayer1->Margin = System::Windows::Forms::Padding(2);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(622, 365);
			this->axWindowsMediaPlayer1->TabIndex = 0;
			this->axWindowsMediaPlayer1->Enter += gcnew System::EventHandler(this, &Video::axWindowsMediaPlayer1_Enter);
			// 
			// Video
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(769, 489);
			this->Controls->Add(this->axWindowsMediaPlayer1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Video";
			this->Text = L"Video";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Video::Video_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Video::Video_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->axWindowsMediaPlayer1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void axWindowsMediaPlayer1_Enter(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Video_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Video_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		
	}
	};
}
