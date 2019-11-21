#pragma once
#include "Subsidiary.h"
#include "FormLight.h"
#include <Windows.h>
#include "raytracer.h"
#include "scene.h"

namespace seliv {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Drawing::Bitmap ^bm;
	private: System::Windows::Forms::PictureBox^  pct;
	private:
		FormLight^ f2;
		
		Pixel* SizeBuf;
		Engine* tracer;
		Col* col;
		Cord *GlobalCord;
		Cord *LCord;
		float GlobalAlpha, GlobalBeta;
		NeedR* flag;
	


	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  lbl4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tB;
	private: System::Windows::Forms::TextBox^  tA;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tZ;
	private: System::Windows::Forms::TextBox^  tY;
	private: System::Windows::Forms::TextBox^  tX;
	private: System::Windows::Forms::ProgressBar^  progrbar;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;




	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  lblres;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ToolStripMenuItem^  сценаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  перемещениеИсточникаСветаToolStripMenuItem;
	private: System::Windows::Forms::Button^  button6;



			 /// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pct = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->lbl4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tB = (gcnew System::Windows::Forms::TextBox());
			this->tA = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tZ = (gcnew System::Windows::Forms::TextBox());
			this->tY = (gcnew System::Windows::Forms::TextBox());
			this->tX = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->progrbar = (gcnew System::Windows::Forms::ProgressBar());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->сценаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->перемещениеИсточникаСветаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblres = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pct))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pct
			// 
			this->pct->Location = System::Drawing::Point(284, 46);
			this->pct->Margin = System::Windows::Forms::Padding(4);
			this->pct->Name = L"pct";
			this->pct->Size = System::Drawing::Size(663, 441);
			this->pct->TabIndex = 1;
			this->pct->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->lbl4);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->tB);
			this->groupBox1->Controls->Add(this->tA);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->tZ);
			this->groupBox1->Controls->Add(this->tY);
			this->groupBox1->Controls->Add(this->tX);
			this->groupBox1->Location = System::Drawing::Point(13, 29);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(263, 441);
			this->groupBox1->TabIndex = 22;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ручной ввод положения камеры";
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(25, 313);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(220, 30);
			this->button6->TabIndex = 28;
			this->button6->Text = L"Переместить источник света";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::перемещениеИсточникаСветаToolStripMenuItem_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(4, 89);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(118, 17);
			this->label8->TabIndex = 35;
			this->label8->Text = L"Поворот камеры";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(25, 276);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(220, 30);
			this->button1->TabIndex = 33;
			this->button1->Text = L"Создать кадр";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(4, 20);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(144, 17);
			this->label7->TabIndex = 34;
			this->label7->Text = L"Координаты камеры";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(8, 194);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(154, 17);
			this->label6->TabIndex = 32;
			this->label6->Text = L"Текущие координаты:";
			// 
			// lbl4
			// 
			this->lbl4->Location = System::Drawing::Point(8, 228);
			this->lbl4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl4->Name = L"lbl4";
			this->lbl4->Size = System::Drawing::Size(197, 58);
			this->lbl4->TabIndex = 31;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(3, 146);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 17);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Поворот по Z";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(4, 119);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 17);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Поворот по Х";
			// 
			// tB
			// 
			this->tB->Location = System::Drawing::Point(127, 143);
			this->tB->Margin = System::Windows::Forms::Padding(4);
			this->tB->Name = L"tB";
			this->tB->Size = System::Drawing::Size(55, 22);
			this->tB->TabIndex = 28;
			this->tB->Text = L"0";
			this->tB->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::tX_KeyPress);
			// 
			// tA
			// 
			this->tA->Location = System::Drawing::Point(128, 116);
			this->tA->Margin = System::Windows::Forms::Padding(4);
			this->tA->Name = L"tA";
			this->tA->Size = System::Drawing::Size(53, 22);
			this->tA->TabIndex = 27;
			this->tA->Text = L"0";
			this->tA->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::tX_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(169, 52);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 17);
			this->label3->TabIndex = 26;
			this->label3->Text = L"Z =";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(84, 52);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 17);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Y =";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(4, 52);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 17);
			this->label1->TabIndex = 24;
			this->label1->Text = L"X =";
			// 
			// tZ
			// 
			this->tZ->Location = System::Drawing::Point(204, 48);
			this->tZ->Margin = System::Windows::Forms::Padding(4);
			this->tZ->Name = L"tZ";
			this->tZ->Size = System::Drawing::Size(49, 22);
			this->tZ->TabIndex = 23;
			this->tZ->Text = L"-55";
			this->tZ->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::tX_KeyPress);
			// 
			// tY
			// 
			this->tY->Location = System::Drawing::Point(124, 48);
			this->tY->Margin = System::Windows::Forms::Padding(4);
			this->tY->Name = L"tY";
			this->tY->Size = System::Drawing::Size(37, 22);
			this->tY->TabIndex = 22;
			this->tY->Text = L"5";
			this->tY->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::tX_KeyPress);
			// 
			// tX
			// 
			this->tX->Location = System::Drawing::Point(43, 48);
			this->tX->Margin = System::Windows::Forms::Padding(4);
			this->tX->Name = L"tX";
			this->tX->Size = System::Drawing::Size(40, 22);
			this->tX->TabIndex = 21;
			this->tX->Text = L"0";
			this->tX->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::tX_KeyPress);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button8);
			this->groupBox2->Controls->Add(this->button7);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Location = System::Drawing::Point(956, 46);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(288, 206);
			this->groupBox2->TabIndex = 24;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Перемещение камеры";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(189, 155);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(83, 28);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Опустить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(189, 119);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(83, 28);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Поднять";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(80, 107);
			this->button8->Margin = System::Windows::Forms::Padding(4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(83, 28);
			this->button8->TabIndex = 6;
			this->button8->Text = L"Назад";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(161, 71);
			this->button7->Margin = System::Windows::Forms::Padding(4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(83, 28);
			this->button7->TabIndex = 5;
			this->button7->Text = L"Вправо";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button5
			// 
			this->button5->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->button5->Location = System::Drawing::Point(0, 71);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(83, 28);
			this->button5->TabIndex = 3;
			this->button5->Text = L"Влево";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(80, 35);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(83, 28);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Вперед";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button13);
			this->groupBox3->Controls->Add(this->button10);
			this->groupBox3->Controls->Add(this->button12);
			this->groupBox3->Controls->Add(this->button11);
			this->groupBox3->Location = System::Drawing::Point(956, 273);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4);
			this->groupBox3->Size = System::Drawing::Size(288, 171);
			this->groupBox3->TabIndex = 25;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Поворот камеры";
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(99, 121);
			this->button13->Margin = System::Windows::Forms::Padding(4);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(83, 28);
			this->button13->TabIndex = 3;
			this->button13->Text = L"Вниз";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
			// 
			// button10
			// 
			this->button10->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->button10->Location = System::Drawing::Point(11, 86);
			this->button10->Margin = System::Windows::Forms::Padding(4);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(83, 28);
			this->button10->TabIndex = 0;
			this->button10->Text = L"Влево";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// button12
			// 
			this->button12->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button12->Location = System::Drawing::Point(99, 50);
			this->button12->Margin = System::Windows::Forms::Padding(4);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(83, 28);
			this->button12->TabIndex = 2;
			this->button12->Text = L"Вверх";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
			// 
			// button11
			// 
			this->button11->ImageAlign = System::Drawing::ContentAlignment::BottomRight;
			this->button11->Location = System::Drawing::Point(189, 86);
			this->button11->Margin = System::Windows::Forms::Padding(4);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(83, 28);
			this->button11->TabIndex = 1;
			this->button11->Text = L"Вправо";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
			// 
			// progrbar
			// 
			this->progrbar->Location = System::Drawing::Point(1020, 472);
			this->progrbar->Margin = System::Windows::Forms::Padding(4);
			this->progrbar->Name = L"progrbar";
			this->progrbar->Size = System::Drawing::Size(208, 16);
			this->progrbar->TabIndex = 24;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->сценаToolStripMenuItem,
					this->файлToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1241, 28);
			this->menuStrip1->TabIndex = 25;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// сценаToolStripMenuItem
			// 
			this->сценаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->перемещениеИсточникаСветаToolStripMenuItem });
			this->сценаToolStripMenuItem->Name = L"сценаToolStripMenuItem";
			this->сценаToolStripMenuItem->Size = System::Drawing::Size(64, 24);
			this->сценаToolStripMenuItem->Text = L"Сцена";
			// 
			// перемещениеИсточникаСветаToolStripMenuItem
			// 
			this->перемещениеИсточникаСветаToolStripMenuItem->Name = L"перемещениеИсточникаСветаToolStripMenuItem";
			this->перемещениеИсточникаСветаToolStripMenuItem->Size = System::Drawing::Size(302, 26);
			this->перемещениеИсточникаСветаToolStripMenuItem->Text = L"Перемещение источника света";
			this->перемещениеИсточникаСветаToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::перемещениеИсточникаСветаToolStripMenuItem_Click);
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->выходToolStripMenuItem });
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(79, 24);
			this->файлToolStripMenuItem->Text = L"Справка";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(179, 26);
			this->выходToolStripMenuItem->Text = L"О программе";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выходToolStripMenuItem_Click);
			// 
			// lblres
			// 
			this->lblres->AutoSize = true;
			this->lblres->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblres->Location = System::Drawing::Point(964, 471);
			this->lblres->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblres->Name = L"lblres";
			this->lblres->Size = System::Drawing::Size(39, 17);
			this->lblres->TabIndex = 27;
			this->lblres->Text = L"Time";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1241, 505);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->lblres);
			this->Controls->Add(this->progrbar);
			this->Controls->Add(this->pct);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Курсовой проект: Селиверстов ИУ7-55";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->EnabledChanged += gcnew System::EventHandler(this, &Form1::Form1_EnabledChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pct))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		void GlobalCordInit()
		{
			GlobalCord = new Cord;
			LCord = new Cord;
			flag = new NeedR;
			flag->f = false;
			LCord->x = tracer->GetScene()->GetLight(0)->GetCentre().x;
			LCord->y = tracer->GetScene()->GetLight(0)->GetCentre().y;
			LCord->z = tracer->GetScene()->GetLight(0)->GetCentre().z;
			GlobalBeta = Convert::ToDouble(tB->Text);
			GlobalAlpha = Convert::ToDouble(tA->Text);
			GlobalCord->x = Convert::ToInt32(tX->Text);
			GlobalCord->y = Convert::ToInt32(tY->Text);
			GlobalCord->z = Convert::ToInt32(tZ->Text);
			tX->Text = "";
			tY->Text = "";
			tZ->Text = "";
		}

		void TracerInit()
		{
			tracer = new Engine();				 
			tracer->GetScene()->InitScene();
			tracer->SettingCanvas(col, pct->Width, pct->Height);
		}


		void InitAll()
		{		
			int r = pct->Width*pct->Height;
			bm = gcnew System::Drawing::Bitmap(pct->Width, pct->Height);
			pct->Image = bm;
		//	NeedRefresh = gcnew bool;
			SizeBuf = new Pixel[r];
			progrbar->Maximum = r;
			col = new Col[r];			
			for (int i =0; i < r; i++)
			{
				col[i].r  = 0;
				col[i].g  = 0;
				col[i].b  = 0;
			}
		}

		void Draw(System::Drawing::Bitmap ^bm, int PctHeight, int PctWidth)
		{
			for(int i =0; i < PctHeight; i++)
				for(int j=0; j < PctWidth; j++)
				{		
					bm->SetPixel(j,i,System::Drawing::Color::FromArgb((int)col[i*PctWidth+j].r, 
								(int)col[i*PctWidth+j].g,(int)col[i*PctWidth+j].b));
				}
			pct->Image = bm;
			pct->Update();
		}

		void StartRaytrace()
		{
				// Инициализация данных.
			float mx, my, mz, anx, any;
			mx = GlobalCord->x;
			my = GlobalCord->y;
			mz = GlobalCord->z;
			anx = GlobalAlpha;
			any = GlobalBeta; 				
			progrbar->Value = 0;
			tracer->InitRender();

				// Старт рендеринга, засекаем время.
			int st = GetTickCount();
			tracer->Render(mx, my, mz, anx, any, progrbar);
			int st2 = GetTickCount();

				// Вывод результатов
			lblres->Text = "Время генерации " + Convert::ToString((st2-st)) + " мс"; 
			Draw(bm,pct->Height, pct->Width);
			progrbar->Value = 0;		
		}

// Проверка на ввод граничных значений комнаты.
void CheckData()
{
	if(GlobalCord->x <= WLeft) GlobalCord->x = WLeft+1;
	if(GlobalCord->x >= WRight-10) GlobalCord->x = WRight-11;
	if(GlobalCord->z <= WWidth) GlobalCord->z = WWidth+1;
	if(GlobalCord->z >= LenW) GlobalCord->z = LenW-1;
	if(GlobalCord->y <= WFloor) GlobalCord->y = WFloor+1;
	if(GlobalCord->y >= HWall+1) GlobalCord->y = HWall;
}

// Проверка на неверный ввод.
bool GoodValue(System::Windows::Forms::TextBox ^t)
{
	if(t->Text->Length == 0)
		return false;
	if(t->Text->Length == 1 && t->Text[0] == '-')
		return false;
	return true;
}


// Проверка на неверный ввод всех полей ввода.
bool CheckTxtBoxes()
{
	return (GoodValue(tX) && GoodValue(tY) 
			&& GoodValue(tZ) && GoodValue(tA)
			&& GoodValue(tB));
}

		// Подготовка к запуску главного алгоритма.
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 
				 if(CheckTxtBoxes())
				 {				 
					 GlobalCord->x = (float)(Convert::ToDouble(tX->Text));;
					 GlobalCord->y = (float)(Convert::ToDouble(tY->Text));;
					 GlobalCord->z = (float)(Convert::ToDouble(tZ->Text));;
					 GlobalBeta = (float)(Convert::ToDouble(tB->Text));
					 GlobalAlpha = (float)(Convert::ToDouble(tA->Text));
					 CheckData();				 
					 RefreshTextBox();
					 StartRaytrace();
					 tX->Text = "";
					 tY->Text = "";
					 tZ->Text = "";
				 }
				 else
					 MessageBox::Show("Ошибка. Неверный ввод данных.");
			 }

		

		// Инициализация
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 InitAll(); 				 
				 TracerInit();
				 GlobalCordInit();				 
				 RefreshCurrCoord();
				 StartRaytrace();
			 }


	private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
			 {
				 delete SizeBuf;
				 delete col;
				 delete flag;
				 delete LCord;
				 delete GlobalCord;
			 }


// Перемещение кнопками.
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 GlobalCord->z += MoveConst;
			 if(GlobalCord->z >= LenW) GlobalCord->z = LenW-1;
			 StartRaytrace();
			 RefreshCurrCoord();
		 }

private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 GlobalCord->z -= MoveConst;
			 if(GlobalCord->z <= WWidth) GlobalCord->z = WWidth+1;
			 StartRaytrace();
			 RefreshCurrCoord();
		 }

private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) 
		 {			 
			 GlobalCord->x += MoveConst;
			 if(GlobalCord->x >= WRight-10) GlobalCord->x = WRight-11;
			 StartRaytrace();
			 RefreshCurrCoord();
		 }

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 GlobalCord->x -= MoveConst;
			 if(GlobalCord->x <= WLeft) GlobalCord->x = WLeft+1;
			 StartRaytrace();
			 RefreshCurrCoord();
		 }

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 GlobalCord->y -= MoveConst;
			 if(GlobalCord->y <= WFloor) GlobalCord->y = WFloor+1;
			 StartRaytrace();
			 RefreshCurrCoord();
		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 GlobalCord->y += MoveConst;
			 if(GlobalCord->y >= HWall+1) GlobalCord->y = HWall;
			 StartRaytrace();
			 RefreshCurrCoord();
		 }
		 

// Поворот кнопками.
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			if(GlobalAlpha >= 360) GlobalAlpha -= 360;
			GlobalAlpha += RotateConst;			
			StartRaytrace();
		 }

private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(GlobalBeta >= 360) GlobalBeta -= 360;
			 GlobalBeta += RotateConst;			 
			 StartRaytrace();
		 }

private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(GlobalAlpha <= -360) GlobalAlpha += 360;
			 GlobalAlpha -= RotateConst;			 
			 StartRaytrace();
		 }

private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(GlobalBeta <= -360) GlobalBeta += 360;
			 GlobalBeta -= RotateConst;			 
			 StartRaytrace();
		 }


// Обновление полей с вводом координат.
private: System::Void tabControl1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {
			 RefreshTextBox();
		 }

void RefreshTextBox()
{
    tX->Text = Convert::ToString(GlobalCord->x);
	tY->Text = Convert::ToString(GlobalCord->y);
	tZ->Text = Convert::ToString(GlobalCord->z);
	tA->Text = Convert::ToString(GlobalAlpha);
	tB->Text = Convert::ToString(GlobalBeta);
	RefreshCurrCoord();
}

// Обновление текущих координат.
void RefreshCurrCoord()
{
	lbl4->Text = "X = " + Convert::ToString(GlobalCord->x)
		+"    Y = " + Convert::ToString(GlobalCord->y) 
		+"    Z = " + Convert::ToString(GlobalCord->z);
}


// Проверка на неверный ввод.
private: System::Void tX_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
{
	TextBox^ TxtBox = safe_cast<TextBox^>(sender); 
			// разрешение на ввод цифр
	 if(!((e->KeyChar <= 57 && e->KeyChar >= 48) 

			// разрешение на использование BackSpace и Tab
		 || e->KeyChar == 9 || e->KeyChar == 8	

			// разрешение на перемещение стрелками
		 || e->KeyChar == 37 || e->KeyChar == 39))		
	 {
		 if(TxtBox->SelectionStart == 0 && e->KeyChar == '-')
		 {
			 if(TxtBox->Text->Length > 1)
			 // разрешение на ввод минуса
			if ((TxtBox->Text[1] == '-'))
			{
				e->KeyChar = '\0';
			}
		 }			
		 else
			e->KeyChar = '\0';
	 }

		// ограничение на максимальный размер строки.
	 if (TxtBox->Text->Length > 5 && e->KeyChar != 8)
		 e->KeyChar = '\0';
}

private: System::Void выходToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 exit(0);
		 }


private: System::Void выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 MessageBox::Show("Программой представлена ёлка, в стеклянном шаре. Имеется возможность перемещать камеру в пространстве комнаты, как с помощью графического интерфейса, так и заданием координат камеры вручную. Размеры комнаты (-25, 25; -4, 40; -80, 30). Поворот вручную осуществляется вводом отрицательного угла - налево, положительного - направо.");
		 }


private: System::Void перемещениеИсточникаСветаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			if(f2) f2->Close();
			
			f2 = gcnew FormLight(this, &LCord->x, &LCord->y, &LCord->z, &flag->f);
			this->AddOwnedForm(f2);
			this->Enabled = false;
			f2->Show(this);
		 }


private: System::Void Form1_EnabledChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(Enabled && flag->f)
			 {
				 tracer->GetScene()->MoveLight(LCord->x, LCord->y, LCord->z);
				 StartRaytrace();
				 flag->f = false;
			 }
		 }

};

}

