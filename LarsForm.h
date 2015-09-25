#pragma once
#include <msclr\marshal_cppstd.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Parser.h"
#include "Translate.h"

namespace LarsProgram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using std::ifstream;


	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class LarsForm : public System::Windows::Forms::Form
	{
	public:
		LarsForm(void)
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
		~LarsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;



	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  historyToolStripMenuItem;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->historyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 36);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(394, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &LarsForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(413, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Run";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LarsForm::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 107);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(394, 211);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(413, 107);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(45, 17);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"C++";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(413, 131);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(49, 17);
			this->checkBox2->TabIndex = 7;
			this->checkBox2->Text = L"Java";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(413, 155);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(59, 17);
			this->checkBox3->TabIndex = 8;
			this->checkBox3->Text = L"Python";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileName = L"*.txt";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(522, 32);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(135, 286);
			this->richTextBox2->TabIndex = 9;
			this->richTextBox2->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(522, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Lars Compiler History";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->viewToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(669, 24);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->saveAsToolStripMenuItem,
					this->loadToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As...";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &LarsForm::saveAsToolStripMenuItem_Click);
			// 
			// loadToolStripMenuItem
			// 
			this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
			this->loadToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->loadToolStripMenuItem->Text = L"Load";
			this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &LarsForm::loadToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(123, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &LarsForm::exitToolStripMenuItem_Click);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->helpToolStripMenuItem,
					this->historyToolStripMenuItem
			});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &LarsForm::helpToolStripMenuItem_Click);
			// 
			// historyToolStripMenuItem
			// 
			this->historyToolStripMenuItem->Name = L"historyToolStripMenuItem";
			this->historyToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->historyToolStripMenuItem->Text = L"History";
			this->historyToolStripMenuItem->Click += gcnew System::EventHandler(this, &LarsForm::historyToolStripMenuItem_Click);
			// 
			// LarsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(669, 337);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"LarsForm";
			this->Text = L"Lars Translator";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->richTextBox1->Text = "";
		fstream outfile;
		parseClass parser;
		outfile.open("out.txt", ios::out);
		//transClass trans;
		System::String^ larsInput = this->textBox1->Text;
		std::string larsInput2 = msclr::interop::marshal_as<std::string>(larsInput);
		outfile << larsInput2 << endl;
		
		parser.parseLars();
		//this->richTextBox1->Text = "Can I do this?";
		string theError = parser.p_printError("");
		outfile << theError << endl;
		String^ str1 = gcnew String(theError.c_str());
		this->richTextBox1->Text += str1;
		string theOutput = parser.p_printTranslation(this->checkBox1->Checked, this->checkBox2->Checked, this->checkBox3->Checked);
		outfile << theOutput << endl;
		String^ str2 = gcnew String(theOutput.c_str());
		this->richTextBox1->Text += str2;
		this->richTextBox2->Text += larsInput + "\n";
		/*if (this->checkBox1->Checked == true)
		{
			
		}
		else if (this->checkBox2->Checked == true)
		{

		}
		else if (this->checkBox2->Checked == true)
		{

		}*/
		//transClass trans;
		//trans.startTranslate(richTextBox1, textBox1);

	}
	
private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//this->saveFileDialog1->ShowDialog();
	fstream outLarsFile;
	{
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		sfd->Filter = "Text Files|*.txt|All Files|*.*";
		if (sfd->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			return;
		}
		//MessageBox::Show( sfd->FileName );
		System::String^ larsFile = sfd->FileName;
		std::string larsFile2 = msclr::interop::marshal_as<std::string>(larsFile);
		outLarsFile.open(larsFile2, ios::out);
		System::String^ larsInput = this->textBox1->Text;
		std::string larsInput2 = msclr::interop::marshal_as<std::string>(larsInput);
		outLarsFile << larsInput2 << endl;
		MessageBox::Show("Saved");
	}

}
private: System::Void loadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		{
			OpenFileDialog^ sfd = gcnew OpenFileDialog();
			sfd->Filter = "Text Files|*.txt|All Files|*.*";
			if (sfd->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				return;
			}
			//MessageBox::Show( sfd->FileName );
			MessageBox::Show("Loading is not available as of yet!");
		}
}
private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->richTextBox1->Text = "";
	this->richTextBox1->Text = "LARS Grammar \n <var - statement>  variable <follow - var> |" +
		"\nfunction <assign> <follow - funct> |\n" +
		"say “…”\n"+
		"<statement>  if expression then <var - statement> <follow - if> |\n"+
		"while expression do <var - statement> <follow - while> |\n"+
			"for <for - expr> times do <var - statement><follow - for> \n"+
				"<follow - var> = expression | [<array>] | E\n"+
				"<array> variable <array - tail> | number <array - tail> | E\n"+
				"<array - tail> , <array> | E\n"+
				"<assign> = | E\n"+
				"<follow - funct>  expression | say “…” | E\n"+
				"<follow - if>, <var - statement><follow - if> | E\n"+
				"<follow - while>, <var - statement><follow - while> | E\n"+
				"<follow - for>, <var - statement><follow - for> | E\n"+
			"Assignment : x = y - z\n"+
					" Function : A_Plus_Z = a + z\n"+
								"If statement : if 1 < 4 then a + b\n"+
								"For loop : for 10 times do A_Plus_Z\n"+
								"While loop : while x > 2 do test, say “Hello”\n"+
							"Print : say “Hello world”\n"+
								"Array : a[x, 2, z]\n";
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	exit(0);
}
private: System::Void historyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->richTextBox2->Visible == true){
		this->richTextBox2->Visible = false;
		this->label1->Visible = false;
	}
	else if (this->richTextBox2->Visible == false){
		this->richTextBox2->Visible = true;
		this->label1->Visible = true;
	}
}
};
}
