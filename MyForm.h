#pragma once
#include <unordered_set>  
#include <msclr/marshal_cppstd.h>

namespace toDoList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using System::Diagnostics::Debug;

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
			this->streak = 0;
			this->milestone = 3;
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
	private: System::Windows::Forms::TextBox^ taskInp;
	protected:

	private: System::Windows::Forms::Button^ addTaskBtn;
	protected:

	protected:

	private: System::Windows::Forms::ListBox^ taskList;
	private: System::Windows::Forms::Label^ taskExistsLabel;
	private: System::Windows::Forms::Button^ Delete;
	private: System::Windows::Forms::Button^ Update;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ taskStreak;
	private: int streak;
	private: int milestone;
	private: System::Windows::Forms::Label^ Congrats;



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
			this->taskInp = (gcnew System::Windows::Forms::TextBox());
			this->addTaskBtn = (gcnew System::Windows::Forms::Button());
			this->taskList = (gcnew System::Windows::Forms::ListBox());
			this->taskExistsLabel = (gcnew System::Windows::Forms::Label());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->Update = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->taskStreak = (gcnew System::Windows::Forms::Label());
			this->Congrats = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// taskInp
			// 
			this->taskInp->Location = System::Drawing::Point(40, 91);
			this->taskInp->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->taskInp->Name = L"taskInp";
			this->taskInp->Size = System::Drawing::Size(292, 26);
			this->taskInp->TabIndex = 0;
			// 
			// addTaskBtn
			// 
			this->addTaskBtn->Location = System::Drawing::Point(394, 80);
			this->addTaskBtn->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->addTaskBtn->Name = L"addTaskBtn";
			this->addTaskBtn->Size = System::Drawing::Size(112, 50);
			this->addTaskBtn->TabIndex = 1;
			this->addTaskBtn->Text = L"Add Task";
			this->addTaskBtn->UseVisualStyleBackColor = true;
			this->addTaskBtn->Click += gcnew System::EventHandler(this, &MyForm::addTaskBtn_Click);
			// 
			// taskList
			// 
			this->taskList->FormattingEnabled = true;
			this->taskList->ItemHeight = 20;
			this->taskList->Location = System::Drawing::Point(40, 167);
			this->taskList->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->taskList->Name = L"taskList";
			this->taskList->Size = System::Drawing::Size(288, 324);
			this->taskList->TabIndex = 2;
			this->taskList->DoubleClick += gcnew System::EventHandler(this, &MyForm::list_item_double_click);
			// 
			// taskExistsLabel
			// 
			this->taskExistsLabel->AutoSize = true;
			this->taskExistsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->taskExistsLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->taskExistsLabel->Location = System::Drawing::Point(91, 77);
			this->taskExistsLabel->Name = L"taskExistsLabel";
			this->taskExistsLabel->Size = System::Drawing::Size(130, 17);
			this->taskExistsLabel->TabIndex = 3;
			this->taskExistsLabel->Text = L"Task Already exists";
			// 
			// Delete
			// 
			this->Delete->Location = System::Drawing::Point(394, 167);
			this->Delete->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(112, 50);
			this->Delete->TabIndex = 3;
			this->Delete->Text = L"Delete";
			this->Delete->UseVisualStyleBackColor = true;
			this->Delete->Click += gcnew System::EventHandler(this, &MyForm::deleteItem);
			// 
			// Update
			// 
			this->Update->Location = System::Drawing::Point(394, 252);
			this->Update->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Update->Name = L"Update";
			this->Update->Size = System::Drawing::Size(112, 50);
			this->Update->TabIndex = 4;
			this->Update->Text = L"Update";
			this->Update->UseVisualStyleBackColor = true;
			this->Update->Click += gcnew System::EventHandler(this, &MyForm::updateItem);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Location = System::Drawing::Point(186, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 40);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Taskify";
			// 
			// taskStreak
			// 
			this->taskStreak->AutoSize = true;
			this->taskStreak->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->taskStreak->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->taskStreak->Location = System::Drawing::Point(346, 335);
			this->taskStreak->Name = L"taskStreak";
			this->taskStreak->Size = System::Drawing::Size(184, 29);
			this->taskStreak->TabIndex = 6;
			this->taskStreak->Text = L"Task Streak is 0";
			// 
			// Congrats
			// 
			this->Congrats->AutoSize = true;
			this->Congrats->Location = System::Drawing::Point(347, 394);
			this->Congrats->Name = L"Congrats";
			this->Congrats->Size = System::Drawing::Size(244, 40);
			this->Congrats->TabIndex = 7;
			this->Congrats->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(541, 528);
			this->Controls->Add(this->Congrats);
			this->Controls->Add(this->taskStreak);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Update);
			this->Controls->Add(this->Delete);
			this->Controls->Add(this->taskList);
			this->Controls->Add(this->addTaskBtn);
			this->Controls->Add(this->taskInp);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"cpp_to_do_list";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/* HASH SET DATA STRUCTURE*/
	private: System::Void addTaskBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ task = taskInp->Text->ToString();
		if (!task->Equals("")) {
			std::string nativeTask = msclr::interop::marshal_as<std::string>(task);

			std::unordered_set<std::string> set;

			/*the to-do list is iterated over and the task at each index is first converted
			to native c++ string and then the substring of each task from position 3 is added to hash set*/

			for (int i = 0;i < taskList->Items->Count;i++) {
				String^ t = taskList->Items[i]->ToString();
				std::string nativeT = msclr::interop::marshal_as<std::string>(t);
				set.insert(nativeT.substr(3));
			}

			/* to check if native task exists in the set and then displaying the label "its exists
			and removing the label after 1sec*/
			if (set.find(nativeTask) != set.end()) {
				this->Controls->Add(this->taskExistsLabel);
				taskInp->Text = "";
				wait(1000);
				this->Controls->Remove(this->taskExistsLabel);
			}
			/*item is added to the list at latest index + 1 and the task_input is set to clear after 
			task has been added to the list.*/
			else {
				taskList->Items->Add((taskList->Items->Count + 1) + ". " + task);
				taskInp->Text = "";
			}
		}
		
	}/*DOUBLE CLICKED ITEMS IN THE LIST*/
	private: System::Void list_item_double_click(System::Object^ sender, System::EventArgs^ e) {
		/*This line retrieves the selected item from the taskList list box 
		(the item that was double-clicked), converts it to a managed .NET Framework string (String^), 
        and assigns it to the task variable */
		String^ task = taskList->SelectedItem->ToString();
		int selectedItem = taskList->Items->IndexOf(task);
		Debug::WriteLine(selectedItem);
		taskList->Items->RemoveAt(selectedItem);
		/*adding a tick to the item */
		taskList->Items->Insert(selectedItem,task + L"\u2713");
		wait(2000);
		/*doubly clicked item removed from the list*/
		taskList->Items->RemoveAt(selectedItem);

		/*to renumber the list items*/
		for (int i = selectedItem;i < taskList->Items->Count;i++) {
			String^ t = taskList->Items[i]->ToString();
			taskList->Items->RemoveAt(i);
			taskList->Items->Insert(i, (i+1)+". "+t->Substring(3));
		}

		if (taskList->Items->Count == 0) {
			streak++;
			taskStreak->Text = "Task Streak is " + streak;
			if (streak == milestone) {
				Congrats->Text = "Your commitment to \nproductivity is truly \ncommendable.";
				wait(3000);
				Congrats->Text = " ";
				milestone *= 2;


	

			}
		}


	}

		   void wait(int n) {
			   DateTime startTime = DateTime::Now;
			   while ((DateTime::Now - startTime).TotalMilliseconds < n) {
				   Application::DoEvents();
			   }
		   }
		   /*DELETE BUTTON FUNCTION*/
		   private: System::Void deleteItem(System::Object^ sender, System::EventArgs^ e) {
			   String^ task = taskList->SelectedItem->ToString();
			   int selectedItem = taskList->Items->IndexOf(task);
			   taskList->Items->Remove(task);
			   for (int i = selectedItem;i < taskList->Items->Count;i++) {
				   String^ t = taskList->Items[i]->ToString();
				   taskList->Items->RemoveAt(i);
				   taskList->Items->Insert(i, (i + 1) + ". " + t->Substring(3));
			   }
		   }
			/*UPDATE BUTTON FUNCTION*/
			private: System::Void updateItem(System::Object^ sender, System::EventArgs^ e) {
				String^ task = taskList->SelectedItem->ToString();
				String^ newTask = taskInp->Text->ToString();
				if (!newTask->Equals("")) {
					int i = taskList->Items->IndexOf(task);
					taskList->Items->RemoveAt(i);
					taskList->Items->Insert(i, (i + 1) + ". " + newTask);
					taskInp->Text = "";
				}
			}

	};
}
