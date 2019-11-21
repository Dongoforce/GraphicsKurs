#pragma once

namespace seliv {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormLight
	/// </summary>
	public ref class FormLight : public System::Windows::Forms::Form
	{
	public:

		FormLight(Form^ f, float* LX, float* LY, float *LZ, bool *fl)
		{
			f1 = f;
			LX2 = LX;
			LY2 = LY;
			LZ2 = LZ;
			flag = fl;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormLight()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblLight;
	private: Form ^f1;
			 float *LX2, *LY2, *LZ2;
			 bool* flag;
			 
			// 
	protected: 

	protected: 
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  zL;
	private: System::Windows::Forms::TextBox^  yL;
	private: System::Windows::Forms::TextBox^  xL;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  закрытьToolStripMenuItem;

	private:
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
			this->lblLight = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->zL = (gcnew System::Windows::Forms::TextBox());
			this->yL = (gcnew System::Windows::Forms::TextBox());
			this->xL = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->закрытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblLight
			// 
			this->lblLight->AutoSize = true;
			this->lblLight->Location = System::Drawing::Point(68, 248);
			this->lblLight->Name = L"lblLight";
			this->lblLight->Size = System::Drawing::Size(0, 13);
			this->lblLight->TabIndex = 13;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->zL);
			this->groupBox1->Controls->Add(this->yL);
			this->groupBox1->Controls->Add(this->xL);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(22, 38);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(241, 165);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			// 
			// zL
			// 
			this->zL->Location = System::Drawing::Point(97, 100);
			this->zL->Name = L"zL";
			this->zL->Size = System::Drawing::Size(44, 20);
			this->zL->TabIndex = 15;
			this->zL->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FormLight::xL_KeyPress);
			// 
			// yL
			// 
			this->yL->Location = System::Drawing::Point(97, 72);
			this->yL->Name = L"yL";
			this->yL->Size = System::Drawing::Size(44, 20);
			this->yL->TabIndex = 14;
			this->yL->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FormLight::xL_KeyPress);
			// 
			// xL
			// 
			this->xL->Location = System::Drawing::Point(97, 45);
			this->xL->Name = L"xL";
			this->xL->Size = System::Drawing::Size(44, 20);
			this->xL->TabIndex = 13;
			this->xL->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FormLight::xL_KeyPress);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(76, 103);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Z";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(76, 75);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(15, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Y";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(76, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(15, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"X";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(5, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(224, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Новые координаты источника света";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Maroon;
			this->button1->Location = System::Drawing::Point(65, 126);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Переместить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormLight::button1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(19, 220);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(237, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Текущие координаты источника света";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->закрытьToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(284, 24);
			this->menuStrip1->TabIndex = 14;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// закрытьToolStripMenuItem
			// 
			this->закрытьToolStripMenuItem->Name = L"закрытьToolStripMenuItem";
			this->закрытьToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->закрытьToolStripMenuItem->Text = L"Закрыть";
			this->закрытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormLight::закрытьToolStripMenuItem_Click);
			// 
			// FormLight
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 281);
			this->Controls->Add(this->lblLight);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"FormLight";
			this->Text = L"Источник света";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormLight::FormLight_FormClosing);
			this->Load += gcnew System::EventHandler(this, &FormLight::FormLight_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void закрытьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
			//	 f1->Enabled = true;
				 Close();
			 }

private: System::Void FormLight_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 lblLight->Text = "X = " + Convert::ToString(*LX2) + "    Y = " 
							+ Convert::ToString(*LY2) + "    Z = " + Convert::ToString(*LZ2);
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
			 return (GoodValue(xL) && GoodValue(zL)  && GoodValue(yL));
		 }

// Запись координат.
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(CheckTxtBoxes())
			 {
				 *LX2 = Convert::ToDouble(xL->Text);	
				 *LY2 = Convert::ToDouble(yL->Text);
				 *LZ2 = Convert::ToDouble(zL->Text);
				 *flag = true;
				 Close();
			 }			 
			 else
				 MessageBox::Show("Ошибка. Неверный ввод данных.");
		 }


private: System::Void xL_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
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
			 if (TxtBox->Text->Length > 3 && e->KeyChar != 8)
				 e->KeyChar = '\0';
		 }

private: System::Void FormLight_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
		 {
			 f1->Enabled = true;
		 }
};
}
