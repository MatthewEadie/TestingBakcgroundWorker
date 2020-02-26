#pragma once

namespace TestingBakcgroundWorker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		int max = 100;
	private: System::Windows::Forms::Button^ btnProcess;
	protected:
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::ProgressBar^ progressBar;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::TextBox^ textBox1;

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
			this->btnProcess = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnProcess
			// 
			this->btnProcess->Location = System::Drawing::Point(36, 27);
			this->btnProcess->Margin = System::Windows::Forms::Padding(4);
			this->btnProcess->Name = L"btnProcess";
			this->btnProcess->Size = System::Drawing::Size(164, 28);
			this->btnProcess->TabIndex = 0;
			this->btnProcess->Text = L"Process";
			this->btnProcess->UseVisualStyleBackColor = true;
			this->btnProcess->Click += gcnew System::EventHandler(this, &MyForm::btnProcess_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(237, 27);
			this->btnCancel->Margin = System::Windows::Forms::Padding(4);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(159, 28);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &MyForm::btnCancel_Click);
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(16, 84);
			this->progressBar->Margin = System::Windows::Forms::Padding(4);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(388, 28);
			this->progressBar->TabIndex = 2;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(32, 154);
			this->label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(46, 17);
			this->label->TabIndex = 3;
			this->label->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 192);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Label2";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(237, 139);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 5;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(237, 186);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(440, 236);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label);
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnProcess);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		label->Text = "";
		label2->Text = "";
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) 	
	{
		int sum = 0;
		//progressBar->Maximum = max;
		for (size_t i = 0; i < max; i++)
		{
			Threading::Thread::Sleep(100);
			sum += i;
			int percent = i * 100 / max;
			backgroundWorker1->ReportProgress(percent);

			if (backgroundWorker1->CancellationPending)
			{
				e->Cancel = true;	//set cancel to true so it will stop on next loop
				backgroundWorker1->ReportProgress(0);
				return;
			}
		}
		e->Result = sum;
	}

	private: System::Void backgroundWorker1_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) 
	{
		textBox1->Text = "Started";
		progressBar->Value = e->ProgressPercentage;
		label->Text = e->ProgressPercentage.ToString() + "%";
	}

	private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) 
	{
		if (e->Cancelled)
		{
			label->Text = "Process Cancelled";
		}
		else if (e->Error != nullptr)
		{
			label->Text = e->Error->Message;
		}
		else
		{
			label->Text = "Sum = " + e->Result;
			progressBar->Value = 0;
		}
	}

	private: System::Void btnProcess_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		double max = (double)numericUpDown1->Value;
		progressBar->Maximum = max;

		//textBox1->Text = progressBar->Maximum.ToString();

		if (!backgroundWorker1->IsBusy)
		{
			backgroundWorker1->RunWorkerAsync();
		}
		else
		{
			label2->Text = "Busy processing please wait";
		}
		
	}

	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (backgroundWorker1->IsBusy)
		{
			backgroundWorker1->CancelAsync();
		}
		else
		{
			label2->Text = "Background worker isn't running";
		}
		
	}

};
}
