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
	private: System::Windows::Forms::Button^ btnProcess;
	protected:
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::ProgressBar^ progressBar;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::Label^ label2;

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
			this->SuspendLayout();
			// 
			// btnProcess
			// 
			this->btnProcess->Location = System::Drawing::Point(27, 22);
			this->btnProcess->Name = L"btnProcess";
			this->btnProcess->Size = System::Drawing::Size(123, 23);
			this->btnProcess->TabIndex = 0;
			this->btnProcess->Text = L"Process";
			this->btnProcess->UseVisualStyleBackColor = true;
			this->btnProcess->Click += gcnew System::EventHandler(this, &MyForm::btnProcess_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(178, 22);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(119, 23);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &MyForm::btnCancel_Click);
			// 
			// progressBar
			// 
			this->progressBar->Location = System::Drawing::Point(12, 68);
			this->progressBar->Name = L"progressBar";
			this->progressBar->Size = System::Drawing::Size(291, 23);
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
			this->label->Location = System::Drawing::Point(24, 125);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(35, 13);
			this->label->TabIndex = 3;
			this->label->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 156);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Label2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(438, 275);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label);
			this->Controls->Add(this->progressBar);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnProcess);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
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
		for (size_t i = 0; i < 100; i++)
		{
			Threading::Thread::Sleep(100);
			sum += i;
			backgroundWorker1->ReportProgress(i);

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
		}
	}

	private: System::Void btnProcess_Click(System::Object^ sender, System::EventArgs^ e) 
	{
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
