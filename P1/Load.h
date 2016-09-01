#pragma once
#include <cstring>
#include "MainForm.h"
using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Threading;

public ref class LoadFromObj
{

public: 
static  System::Windows::Forms::OpenFileDialog^  openFileDialog;
static	System::Windows::Forms::RichTextBox^  richTextBox;
static	System::Windows::Forms::RichTextBox^  v;
static	System::Windows::Forms::RichTextBox^  vt;
static	System::Windows::Forms::RichTextBox^  vn;
static	System::Windows::Forms::RichTextBox^  f;


public:
	void LoadFromFile()
	{	
		Encoding ^enc;
		richTextBox->Text = File::ReadAllText(openFileDialog->FileName, enc->GetEncoding("windows-1251"));


			String^ varv = "v ";String^ varvt = "vt";String^ varvn = "vn";String^ varf = "f ";
			int i = 0;
			while (richTextBox->Lines[i] != "")
			{
				String^ buf = "\n" + richTextBox->Lines[i];
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
};
