#pragma once
#include <cstdio>
#include "Load.h"
namespace P1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  v;
	private: System::Windows::Forms::RichTextBox^  vt;
	private: System::Windows::Forms::RichTextBox^  vn;
	private: System::Windows::Forms::RichTextBox^  f;

	delegate void SetVoidDelegate();

	private: System::Void ChangeText()
	{
		if (this->richTextBox1->InvokeRequired)
		{
			SetVoidDelegate^ d = gcnew SetVoidDelegate(this, &MainForm::ChangeText);
			this->Invoke(d);
		}
		else
		{
			Encoding ^enc;
			richTextBox1->Text = File::ReadAllText(openFileDialog1->FileName, enc->GetEncoding("windows-1251"));
			String^ varv = "v ";String^ varvt = "vt";String^ varvn = "vn";String^ varf = "f ";
			int i = 0;
			while (richTextBox1->Lines[i] != "")
			{
				String^ buf = "\n" + richTextBox1->Lines[i];
				//////
				if (buf->IndexOf(varv) != -1)
				{
					v->Text += buf;
				}
				/////
				if (buf->IndexOf(varvt) != -1)
				{
					vt->Text += buf;
				}
				/////
				if (buf->IndexOf(varvn) != -1)
				{
					vn->Text += buf;
				}
				//////
				if (buf->IndexOf(varf) != -1)
				{
					f->Text += buf;
				}
				i++;
			}
		}
	}

	public:	void LoadFromFile()
		{
			
			this->ChangeText();

		}



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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->v = (gcnew System::Windows::Forms::RichTextBox());
			this->vt = (gcnew System::Windows::Forms::RichTextBox());
			this->vn = (gcnew System::Windows::Forms::RichTextBox());
			this->f = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(60, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"OpenFile";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 52);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox1->Size = System::Drawing::Size(207, 443);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// v
			// 
			this->v->Location = System::Drawing::Point(225, 52);
			this->v->Name = L"v";
			this->v->ReadOnly = true;
			this->v->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->v->Size = System::Drawing::Size(187, 443);
			this->v->TabIndex = 2;
			this->v->Text = L"";
			// 
			// vt
			// 
			this->vt->Location = System::Drawing::Point(418, 52);
			this->vt->Name = L"vt";
			this->vt->ReadOnly = true;
			this->vt->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->vt->Size = System::Drawing::Size(187, 443);
			this->vt->TabIndex = 3;
			this->vt->Text = L"";
			// 
			// vn
			// 
			this->vn->Location = System::Drawing::Point(611, 52);
			this->vn->Name = L"vn";
			this->vn->ReadOnly = true;
			this->vn->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->vn->Size = System::Drawing::Size(187, 443);
			this->vn->TabIndex = 4;
			this->vn->Text = L"";
			// 
			// f
			// 
			this->f->Location = System::Drawing::Point(804, 52);
			this->f->Name = L"f";
			this->f->ReadOnly = true;
			this->f->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->f->Size = System::Drawing::Size(187, 443);
			this->f->TabIndex = 5;
			this->f->Text = L"";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(998, 504);
			this->Controls->Add(this->f);
			this->Controls->Add(this->vn);
			this->Controls->Add(this->vt);
			this->Controls->Add(this->v);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ParseFile";
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->Filter = "Files|*.obj";
		openFileDialog1->FileName = "";		
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			/*		LoadFromObj^ LFO = gcnew LoadFromObj;
					LFO->openFileDialog = openFileDialog1;
					LFO->richTextBox = richTextBox1;
					LFO->v = v;
					LFO->vt = vt;
					LFO->vn = vn;
					LFO->f = f;
			*/
		}
			Thread^ th = gcnew Thread(gcnew ThreadStart(this, &MainForm::LoadFromFile));
		
			th->Start();
				
	}
	};
}
