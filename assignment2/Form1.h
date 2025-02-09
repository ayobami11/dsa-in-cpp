#pragma once

#include "LinkedList.h";

namespace linked_list_with_windows_form
{

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for Form1
    /// </summary>
public
    ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        LinkedList ^ list;

        Form1(void)
        {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
            list = gcnew LinkedList();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button ^ button1;

    protected:
    private:
        System::Windows::Forms::Label ^ label1;

    private:
        System::Windows::Forms::Button ^ button2;

    private:
        System::Windows::Forms::Button ^ button3;

    private:
        System::Windows::Forms::TextBox ^ textBox1;

    private:
        System::Windows::Forms::Button ^ button4;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            //
            // button1
            //
            this->button1->Location = System::Drawing::Point(12, 124);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(120, 28);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Display nodes";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(34, 40);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(53, 17);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Nodes:";
            this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
            //
            // button2
            //
            this->button2->Location = System::Drawing::Point(12, 158);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(248, 32);
            this->button2->TabIndex = 2;
            this->button2->Text = L"Display nodes in reverse order";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
            //
            // button3
            //
            this->button3->Location = System::Drawing::Point(121, 78);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(109, 28);
            this->button3->TabIndex = 3;
            this->button3->Text = L"Append node";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
            //
            // textBox1
            //
            this->textBox1->Location = System::Drawing::Point(15, 78);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(100, 28);
            this->textBox1->TabIndex = 4;
            this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
            //
            // button4
            //
            this->button4->Location = System::Drawing::Point(15, 196);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(100, 29);
            this->button4->TabIndex = 5;
            this->button4->Text = L"Delete list";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
            //
            // Form1
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(282, 253);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button1);
            this->Name = L"Form1";
            this->Text = L"Linked list form";
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
    private:
        System::Void Form1_Load(System::Object ^ sender, System::EventArgs ^ e)
        {
        }

        // Display nodes button
    private:
        System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e)
        {

            // label1->Text = list->displayNodes();
            if (list->getSize() == 0)
            {
                MessageBox::Show("The list is empty!");
            }
            else
            {
                MessageBox::Show(list->displayNodes());
            }
        };

    private:
        System::Void label1_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
        }

        // Display nodes in reverse order button
    private:
        System::Void button2_Click(System::Object ^ sender, System::EventArgs ^ e)
        {

            // label1->Text = list->displayNodesReverse();
            if (list->getSize() == 0)
            {
                MessageBox::Show("The list is empty!");
            }
            else
            {
                MessageBox::Show(list->displayNodesReverse());
            }
        }

        // Append node button
    private:
        System::Void button3_Click(System::Object ^ sender, System::EventArgs ^ e)
        {

            if (textBox1->Text == "")
            {
                MessageBox::Show("Please provide a value to be appended.");
            }
            else
            {

                int num = System::Convert::ToDouble(textBox1->Text);

                list->appendNode(num);

                // MessageBox::Show("Node(" + num + ") has been added to the linked list.");

                label1->Text = list->displayNodes();

                textBox1->Text = "";
            }
        }

    private:
        System::Void textBox1_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
        {
        }

        // Delete list button
    private:
        System::Void button4_Click(System::Object ^ sender, System::EventArgs ^ e)
        {

            list->destroyList();

            label1->Text = "Nodes:";
        }
    };
};
