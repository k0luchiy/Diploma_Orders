#pragma once

namespace DiplomaOrders {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InventoryForm
	/// </summary>
	public ref class InventoryForm : public System::Windows::Forms::Form
	{
	public:
		InventoryForm(void)
		{
			InitializeComponent();

			select_fill_dataGrid();
			select_fill_order_dataGrid();
			select_fill_order_history();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InventoryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ AboutMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ExitMenuItem;
	private: System::Windows::Forms::TabControl^ main_tabContainer;
	private: System::Windows::Forms::TabPage^ inventory_tabPage;
	private: System::Windows::Forms::TabPage^ order_tabPage;
	private: System::Windows::Forms::TabPage^ history_tabPage;
	private: System::Windows::Forms::TableLayoutPanel^ table_main_inventory;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::GroupBox^ groupBox_id;
	private: System::Windows::Forms::TextBox^ id_textBox;
	private: System::Windows::Forms::GroupBox^ category_groupBox;
	private: System::Windows::Forms::TextBox^ category_textBox;
	private: System::Windows::Forms::GroupBox^ groupBox_name;
	private: System::Windows::Forms::TextBox^ name_textBox;
	private: System::Windows::Forms::GroupBox^ groupBox_unnits;
	private: System::Windows::Forms::TextBox^ units_textBox;
	private: System::Windows::Forms::GroupBox^ groupBox_caseQuantity;
	private: System::Windows::Forms::TextBox^ caseQuantity_textBox;
	private: System::Windows::Forms::GroupBox^ groupBox_quntity;
	private: System::Windows::Forms::TextBox^ quantity_textBox;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Button^ clear_btn;
	private: System::Windows::Forms::Button^ put_quantity_btn;
	private: System::Windows::Forms::Button^ calc_btn;

	private: System::Windows::Forms::Button^ find_btn;
	private: System::Windows::Forms::DataGridView^ inventory_datagrid;


	private: System::Data::SqlClient::SqlConnection^ con;
	private: System::Data::DataSet^ inventory_dataset;
	private: System::Data::DataSet^ order_dataset;
	private: System::Data::DataSet^ order_history_dataset;
	private: System::Windows::Forms::TableLayoutPanel^ order_table;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::GroupBox^ groupBox_price_order;
	private: System::Windows::Forms::TextBox^ price_order_textBox;


	private: System::Windows::Forms::GroupBox^ groupBox_supplier_order;
	private: System::Windows::Forms::TextBox^ supplier_order_textBox;
	private: System::Windows::Forms::GroupBox^ groupBox_quantity_order;
	private: System::Windows::Forms::TextBox^ quantity_order_textBox;




	private: System::Windows::Forms::GroupBox^ groupBox_date_order;




	private: System::Windows::Forms::GroupBox^ groupBox_name_order;
	private: System::Windows::Forms::TextBox^ name_order_textBox;
	private: System::Windows::Forms::GroupBox^ gB_id;
	private: System::Windows::Forms::TextBox^ id_order_textbox;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
	private: System::Windows::Forms::Button^ put_quantity_order_btn;

	private: System::Windows::Forms::Button^ create_order_btn;

	private: System::Windows::Forms::Button^ find_order_btn;

	private: System::Windows::Forms::Button^ clear_order_btn;
	private: System::Windows::Forms::DataGridView^ order_dataGrid;


	private: System::Windows::Forms::MaskedTextBox^ deliveryDate_textBox;
	private: System::Windows::Forms::DataGridView^ order_history_dataGrid;












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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->AboutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExitMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->main_tabContainer = (gcnew System::Windows::Forms::TabControl());
			this->inventory_tabPage = (gcnew System::Windows::Forms::TabPage());
			this->table_main_inventory = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox_unnits = (gcnew System::Windows::Forms::GroupBox());
			this->units_textBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_caseQuantity = (gcnew System::Windows::Forms::GroupBox());
			this->caseQuantity_textBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_quntity = (gcnew System::Windows::Forms::GroupBox());
			this->quantity_textBox = (gcnew System::Windows::Forms::TextBox());
			this->category_groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->category_textBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_name = (gcnew System::Windows::Forms::GroupBox());
			this->name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_id = (gcnew System::Windows::Forms::GroupBox());
			this->id_textBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->put_quantity_btn = (gcnew System::Windows::Forms::Button());
			this->calc_btn = (gcnew System::Windows::Forms::Button());
			this->find_btn = (gcnew System::Windows::Forms::Button());
			this->clear_btn = (gcnew System::Windows::Forms::Button());
			this->inventory_datagrid = (gcnew System::Windows::Forms::DataGridView());
			this->order_tabPage = (gcnew System::Windows::Forms::TabPage());
			this->order_table = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox_price_order = (gcnew System::Windows::Forms::GroupBox());
			this->price_order_textBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_supplier_order = (gcnew System::Windows::Forms::GroupBox());
			this->supplier_order_textBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_quantity_order = (gcnew System::Windows::Forms::GroupBox());
			this->quantity_order_textBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_date_order = (gcnew System::Windows::Forms::GroupBox());
			this->deliveryDate_textBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->groupBox_name_order = (gcnew System::Windows::Forms::GroupBox());
			this->name_order_textBox = (gcnew System::Windows::Forms::TextBox());
			this->gB_id = (gcnew System::Windows::Forms::GroupBox());
			this->id_order_textbox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->put_quantity_order_btn = (gcnew System::Windows::Forms::Button());
			this->create_order_btn = (gcnew System::Windows::Forms::Button());
			this->find_order_btn = (gcnew System::Windows::Forms::Button());
			this->clear_order_btn = (gcnew System::Windows::Forms::Button());
			this->order_dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->history_tabPage = (gcnew System::Windows::Forms::TabPage());
			this->con = (gcnew System::Data::SqlClient::SqlConnection());
			this->inventory_dataset = (gcnew System::Data::DataSet());
			this->order_dataset = (gcnew System::Data::DataSet());
			this->order_history_dataset = (gcnew System::Data::DataSet());
			this->order_history_dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->main_tabContainer->SuspendLayout();
			this->inventory_tabPage->SuspendLayout();
			this->table_main_inventory->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->groupBox_unnits->SuspendLayout();
			this->groupBox_caseQuantity->SuspendLayout();
			this->groupBox_quntity->SuspendLayout();
			this->category_groupBox->SuspendLayout();
			this->groupBox_name->SuspendLayout();
			this->groupBox_id->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inventory_datagrid))->BeginInit();
			this->order_tabPage->SuspendLayout();
			this->order_table->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox_price_order->SuspendLayout();
			this->groupBox_supplier_order->SuspendLayout();
			this->groupBox_quantity_order->SuspendLayout();
			this->groupBox_date_order->SuspendLayout();
			this->groupBox_name_order->SuspendLayout();
			this->gB_id->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->order_dataGrid))->BeginInit();
			this->history_tabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inventory_dataset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->order_dataset))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->order_history_dataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->AboutMenuItem, this->ExitMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(634, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// AboutMenuItem
			// 
			this->AboutMenuItem->Name = L"AboutMenuItem";
			this->AboutMenuItem->Size = System::Drawing::Size(94, 20);
			this->AboutMenuItem->Text = L"О программе";
			// 
			// ExitMenuItem
			// 
			this->ExitMenuItem->Name = L"ExitMenuItem";
			this->ExitMenuItem->Size = System::Drawing::Size(54, 20);
			this->ExitMenuItem->Text = L"Выход";
			// 
			// main_tabContainer
			// 
			this->main_tabContainer->Controls->Add(this->inventory_tabPage);
			this->main_tabContainer->Controls->Add(this->order_tabPage);
			this->main_tabContainer->Controls->Add(this->history_tabPage);
			this->main_tabContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->main_tabContainer->Location = System::Drawing::Point(0, 24);
			this->main_tabContainer->Name = L"main_tabContainer";
			this->main_tabContainer->SelectedIndex = 0;
			this->main_tabContainer->Size = System::Drawing::Size(634, 405);
			this->main_tabContainer->TabIndex = 1;
			// 
			// inventory_tabPage
			// 
			this->inventory_tabPage->Controls->Add(this->table_main_inventory);
			this->inventory_tabPage->Location = System::Drawing::Point(4, 22);
			this->inventory_tabPage->Name = L"inventory_tabPage";
			this->inventory_tabPage->Padding = System::Windows::Forms::Padding(3);
			this->inventory_tabPage->Size = System::Drawing::Size(626, 379);
			this->inventory_tabPage->TabIndex = 0;
			this->inventory_tabPage->Text = L"Инвентаризация ";
			this->inventory_tabPage->UseVisualStyleBackColor = true;
			// 
			// table_main_inventory
			// 
			this->table_main_inventory->ColumnCount = 1;
			this->table_main_inventory->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->table_main_inventory->Controls->Add(this->tableLayoutPanel1, 0, 0);
			this->table_main_inventory->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->table_main_inventory->Controls->Add(this->inventory_datagrid, 0, 2);
			this->table_main_inventory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->table_main_inventory->Location = System::Drawing::Point(3, 3);
			this->table_main_inventory->Name = L"table_main_inventory";
			this->table_main_inventory->RowCount = 3;
			this->table_main_inventory->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				25.73726F)));
			this->table_main_inventory->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				9.651475F)));
			this->table_main_inventory->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				64.61126F)));
			this->table_main_inventory->Size = System::Drawing::Size(620, 373);
			this->table_main_inventory->TabIndex = 0;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->groupBox_unnits, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->groupBox_caseQuantity, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->groupBox_quntity, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->category_groupBox, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->groupBox_name, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->groupBox_id, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(614, 89);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// groupBox_unnits
			// 
			this->groupBox_unnits->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_unnits->Controls->Add(this->units_textBox);
			this->groupBox_unnits->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_unnits->Location = System::Drawing::Point(207, 47);
			this->groupBox_unnits->Name = L"groupBox_unnits";
			this->groupBox_unnits->Size = System::Drawing::Size(198, 39);
			this->groupBox_unnits->TabIndex = 5;
			this->groupBox_unnits->TabStop = false;
			this->groupBox_unnits->Text = L"Ед. измерения";
			// 
			// units_textBox
			// 
			this->units_textBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->units_textBox->Location = System::Drawing::Point(3, 16);
			this->units_textBox->Name = L"units_textBox";
			this->units_textBox->ReadOnly = true;
			this->units_textBox->Size = System::Drawing::Size(192, 20);
			this->units_textBox->TabIndex = 0;
			// 
			// groupBox_caseQuantity
			// 
			this->groupBox_caseQuantity->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_caseQuantity->Controls->Add(this->caseQuantity_textBox);
			this->groupBox_caseQuantity->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_caseQuantity->Location = System::Drawing::Point(3, 47);
			this->groupBox_caseQuantity->Name = L"groupBox_caseQuantity";
			this->groupBox_caseQuantity->Size = System::Drawing::Size(198, 39);
			this->groupBox_caseQuantity->TabIndex = 4;
			this->groupBox_caseQuantity->TabStop = false;
			this->groupBox_caseQuantity->Text = L"Количество в кейсе";
			// 
			// caseQuantity_textBox
			// 
			this->caseQuantity_textBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->caseQuantity_textBox->Location = System::Drawing::Point(3, 16);
			this->caseQuantity_textBox->Name = L"caseQuantity_textBox";
			this->caseQuantity_textBox->ReadOnly = true;
			this->caseQuantity_textBox->Size = System::Drawing::Size(192, 20);
			this->caseQuantity_textBox->TabIndex = 0;
			// 
			// groupBox_quntity
			// 
			this->groupBox_quntity->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_quntity->Controls->Add(this->quantity_textBox);
			this->groupBox_quntity->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_quntity->Location = System::Drawing::Point(411, 47);
			this->groupBox_quntity->Name = L"groupBox_quntity";
			this->groupBox_quntity->Size = System::Drawing::Size(200, 39);
			this->groupBox_quntity->TabIndex = 3;
			this->groupBox_quntity->TabStop = false;
			this->groupBox_quntity->Text = L"Количество";
			// 
			// quantity_textBox
			// 
			this->quantity_textBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->quantity_textBox->Location = System::Drawing::Point(3, 16);
			this->quantity_textBox->Name = L"quantity_textBox";
			this->quantity_textBox->Size = System::Drawing::Size(194, 20);
			this->quantity_textBox->TabIndex = 0;
			// 
			// category_groupBox
			// 
			this->category_groupBox->BackColor = System::Drawing::Color::Transparent;
			this->category_groupBox->Controls->Add(this->category_textBox);
			this->category_groupBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->category_groupBox->Location = System::Drawing::Point(411, 3);
			this->category_groupBox->Name = L"category_groupBox";
			this->category_groupBox->Size = System::Drawing::Size(200, 38);
			this->category_groupBox->TabIndex = 2;
			this->category_groupBox->TabStop = false;
			this->category_groupBox->Text = L"Категория";
			// 
			// category_textBox
			// 
			this->category_textBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->category_textBox->Location = System::Drawing::Point(3, 16);
			this->category_textBox->Name = L"category_textBox";
			this->category_textBox->Size = System::Drawing::Size(194, 20);
			this->category_textBox->TabIndex = 0;
			// 
			// groupBox_name
			// 
			this->groupBox_name->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_name->Controls->Add(this->name_textBox);
			this->groupBox_name->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_name->Location = System::Drawing::Point(207, 3);
			this->groupBox_name->Name = L"groupBox_name";
			this->groupBox_name->Size = System::Drawing::Size(198, 38);
			this->groupBox_name->TabIndex = 1;
			this->groupBox_name->TabStop = false;
			this->groupBox_name->Text = L"Название";
			// 
			// name_textBox
			// 
			this->name_textBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->name_textBox->Location = System::Drawing::Point(3, 16);
			this->name_textBox->Name = L"name_textBox";
			this->name_textBox->Size = System::Drawing::Size(192, 20);
			this->name_textBox->TabIndex = 0;
			// 
			// groupBox_id
			// 
			this->groupBox_id->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_id->Controls->Add(this->id_textBox);
			this->groupBox_id->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_id->Location = System::Drawing::Point(3, 3);
			this->groupBox_id->Name = L"groupBox_id";
			this->groupBox_id->Size = System::Drawing::Size(198, 38);
			this->groupBox_id->TabIndex = 0;
			this->groupBox_id->TabStop = false;
			this->groupBox_id->Text = L"Код продукции";
			// 
			// id_textBox
			// 
			this->id_textBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->id_textBox->Location = System::Drawing::Point(3, 16);
			this->id_textBox->Name = L"id_textBox";
			this->id_textBox->Size = System::Drawing::Size(192, 20);
			this->id_textBox->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 4;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->Controls->Add(this->put_quantity_btn, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->calc_btn, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->find_btn, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->clear_btn, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 98);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(614, 30);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// put_quantity_btn
			// 
			this->put_quantity_btn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->put_quantity_btn->Location = System::Drawing::Point(462, 3);
			this->put_quantity_btn->Name = L"put_quantity_btn";
			this->put_quantity_btn->Size = System::Drawing::Size(149, 24);
			this->put_quantity_btn->TabIndex = 3;
			this->put_quantity_btn->Text = L"Записать";
			this->put_quantity_btn->UseVisualStyleBackColor = true;
			this->put_quantity_btn->Click += gcnew System::EventHandler(this, &InventoryForm::put_quantity_btn_Click);
			// 
			// calc_btn
			// 
			this->calc_btn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->calc_btn->Location = System::Drawing::Point(309, 3);
			this->calc_btn->Name = L"calc_btn";
			this->calc_btn->Size = System::Drawing::Size(147, 24);
			this->calc_btn->TabIndex = 2;
			this->calc_btn->Text = L"Создать заказ";
			this->calc_btn->UseVisualStyleBackColor = true;
			this->calc_btn->Click += gcnew System::EventHandler(this, &InventoryForm::calc_btn_Click);
			// 
			// find_btn
			// 
			this->find_btn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->find_btn->Location = System::Drawing::Point(156, 3);
			this->find_btn->Name = L"find_btn";
			this->find_btn->Size = System::Drawing::Size(147, 24);
			this->find_btn->TabIndex = 1;
			this->find_btn->Text = L"Найти";
			this->find_btn->UseVisualStyleBackColor = true;
			this->find_btn->Click += gcnew System::EventHandler(this, &InventoryForm::find_btn_Click);
			// 
			// clear_btn
			// 
			this->clear_btn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->clear_btn->Location = System::Drawing::Point(3, 3);
			this->clear_btn->Name = L"clear_btn";
			this->clear_btn->Size = System::Drawing::Size(147, 24);
			this->clear_btn->TabIndex = 0;
			this->clear_btn->Text = L"Очистить";
			this->clear_btn->UseVisualStyleBackColor = true;
			this->clear_btn->Click += gcnew System::EventHandler(this, &InventoryForm::clear_btn_Click);
			// 
			// inventory_datagrid
			// 
			this->inventory_datagrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->inventory_datagrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->inventory_datagrid->Location = System::Drawing::Point(3, 134);
			this->inventory_datagrid->MultiSelect = false;
			this->inventory_datagrid->Name = L"inventory_datagrid";
			this->inventory_datagrid->Size = System::Drawing::Size(614, 236);
			this->inventory_datagrid->TabIndex = 2;
			this->inventory_datagrid->SelectionChanged += gcnew System::EventHandler(this, &InventoryForm::inventory_datagrid_SelectionChanged);
			// 
			// order_tabPage
			// 
			this->order_tabPage->Controls->Add(this->order_table);
			this->order_tabPage->Location = System::Drawing::Point(4, 22);
			this->order_tabPage->Name = L"order_tabPage";
			this->order_tabPage->Padding = System::Windows::Forms::Padding(3);
			this->order_tabPage->Size = System::Drawing::Size(626, 379);
			this->order_tabPage->TabIndex = 1;
			this->order_tabPage->Text = L"Заказ";
			this->order_tabPage->UseVisualStyleBackColor = true;
			// 
			// order_table
			// 
			this->order_table->ColumnCount = 1;
			this->order_table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->order_table->Controls->Add(this->tableLayoutPanel4, 0, 0);
			this->order_table->Controls->Add(this->tableLayoutPanel5, 0, 1);
			this->order_table->Controls->Add(this->order_dataGrid, 0, 2);
			this->order_table->Dock = System::Windows::Forms::DockStyle::Fill;
			this->order_table->Location = System::Drawing::Point(3, 3);
			this->order_table->Name = L"order_table";
			this->order_table->RowCount = 3;
			this->order_table->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25.73726F)));
			this->order_table->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.651475F)));
			this->order_table->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 64.61126F)));
			this->order_table->Size = System::Drawing::Size(620, 373);
			this->order_table->TabIndex = 1;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 3;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel4->Controls->Add(this->groupBox_price_order, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->groupBox_supplier_order, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->groupBox_quantity_order, 2, 1);
			this->tableLayoutPanel4->Controls->Add(this->groupBox_date_order, 2, 0);
			this->tableLayoutPanel4->Controls->Add(this->groupBox_name_order, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->gB_id, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(614, 89);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// groupBox_price_order
			// 
			this->groupBox_price_order->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_price_order->Controls->Add(this->price_order_textBox);
			this->groupBox_price_order->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_price_order->Location = System::Drawing::Point(207, 47);
			this->groupBox_price_order->Name = L"groupBox_price_order";
			this->groupBox_price_order->Size = System::Drawing::Size(198, 39);
			this->groupBox_price_order->TabIndex = 5;
			this->groupBox_price_order->TabStop = false;
			this->groupBox_price_order->Text = L"Цена за кейс";
			// 
			// price_order_textBox
			// 
			this->price_order_textBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->price_order_textBox->Location = System::Drawing::Point(3, 16);
			this->price_order_textBox->Name = L"price_order_textBox";
			this->price_order_textBox->ReadOnly = true;
			this->price_order_textBox->Size = System::Drawing::Size(192, 20);
			this->price_order_textBox->TabIndex = 0;
			// 
			// groupBox_supplier_order
			// 
			this->groupBox_supplier_order->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_supplier_order->Controls->Add(this->supplier_order_textBox);
			this->groupBox_supplier_order->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_supplier_order->Location = System::Drawing::Point(3, 47);
			this->groupBox_supplier_order->Name = L"groupBox_supplier_order";
			this->groupBox_supplier_order->Size = System::Drawing::Size(198, 39);
			this->groupBox_supplier_order->TabIndex = 4;
			this->groupBox_supplier_order->TabStop = false;
			this->groupBox_supplier_order->Text = L"Поставщик";
			// 
			// supplier_order_textBox
			// 
			this->supplier_order_textBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->supplier_order_textBox->Location = System::Drawing::Point(3, 16);
			this->supplier_order_textBox->Name = L"supplier_order_textBox";
			this->supplier_order_textBox->ReadOnly = true;
			this->supplier_order_textBox->Size = System::Drawing::Size(192, 20);
			this->supplier_order_textBox->TabIndex = 0;
			// 
			// groupBox_quantity_order
			// 
			this->groupBox_quantity_order->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_quantity_order->Controls->Add(this->quantity_order_textBox);
			this->groupBox_quantity_order->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_quantity_order->Location = System::Drawing::Point(411, 47);
			this->groupBox_quantity_order->Name = L"groupBox_quantity_order";
			this->groupBox_quantity_order->Size = System::Drawing::Size(200, 39);
			this->groupBox_quantity_order->TabIndex = 3;
			this->groupBox_quantity_order->TabStop = false;
			this->groupBox_quantity_order->Text = L"Количество кейсов";
			// 
			// quantity_order_textBox
			// 
			this->quantity_order_textBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->quantity_order_textBox->Location = System::Drawing::Point(3, 16);
			this->quantity_order_textBox->Name = L"quantity_order_textBox";
			this->quantity_order_textBox->Size = System::Drawing::Size(194, 20);
			this->quantity_order_textBox->TabIndex = 0;
			// 
			// groupBox_date_order
			// 
			this->groupBox_date_order->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_date_order->Controls->Add(this->deliveryDate_textBox);
			this->groupBox_date_order->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_date_order->Location = System::Drawing::Point(411, 3);
			this->groupBox_date_order->Name = L"groupBox_date_order";
			this->groupBox_date_order->Size = System::Drawing::Size(200, 38);
			this->groupBox_date_order->TabIndex = 2;
			this->groupBox_date_order->TabStop = false;
			this->groupBox_date_order->Text = L"Дата доставки";
			// 
			// deliveryDate_textBox
			// 
			this->deliveryDate_textBox->Culture = (gcnew System::Globalization::CultureInfo(L"ru-RU"));
			this->deliveryDate_textBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->deliveryDate_textBox->Location = System::Drawing::Point(3, 16);
			this->deliveryDate_textBox->Mask = L"00/00/0000";
			this->deliveryDate_textBox->Name = L"deliveryDate_textBox";
			this->deliveryDate_textBox->Size = System::Drawing::Size(194, 20);
			this->deliveryDate_textBox->TabIndex = 0;
			this->deliveryDate_textBox->ValidatingType = System::DateTime::typeid;
			// 
			// groupBox_name_order
			// 
			this->groupBox_name_order->BackColor = System::Drawing::Color::Transparent;
			this->groupBox_name_order->Controls->Add(this->name_order_textBox);
			this->groupBox_name_order->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_name_order->Location = System::Drawing::Point(207, 3);
			this->groupBox_name_order->Name = L"groupBox_name_order";
			this->groupBox_name_order->Size = System::Drawing::Size(198, 38);
			this->groupBox_name_order->TabIndex = 1;
			this->groupBox_name_order->TabStop = false;
			this->groupBox_name_order->Text = L"Название";
			// 
			// name_order_textBox
			// 
			this->name_order_textBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->name_order_textBox->Location = System::Drawing::Point(3, 16);
			this->name_order_textBox->Name = L"name_order_textBox";
			this->name_order_textBox->Size = System::Drawing::Size(192, 20);
			this->name_order_textBox->TabIndex = 0;
			// 
			// gB_id
			// 
			this->gB_id->BackColor = System::Drawing::Color::Transparent;
			this->gB_id->Controls->Add(this->id_order_textbox);
			this->gB_id->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gB_id->Location = System::Drawing::Point(3, 3);
			this->gB_id->Name = L"gB_id";
			this->gB_id->Size = System::Drawing::Size(198, 38);
			this->gB_id->TabIndex = 0;
			this->gB_id->TabStop = false;
			this->gB_id->Text = L"Код продукции";
			// 
			// id_order_textbox
			// 
			this->id_order_textbox->Dock = System::Windows::Forms::DockStyle::Top;
			this->id_order_textbox->Location = System::Drawing::Point(3, 16);
			this->id_order_textbox->Name = L"id_order_textbox";
			this->id_order_textbox->Size = System::Drawing::Size(192, 20);
			this->id_order_textbox->TabIndex = 0;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 4;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel5->Controls->Add(this->put_quantity_order_btn, 3, 0);
			this->tableLayoutPanel5->Controls->Add(this->create_order_btn, 2, 0);
			this->tableLayoutPanel5->Controls->Add(this->find_order_btn, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->clear_order_btn, 0, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 98);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(614, 30);
			this->tableLayoutPanel5->TabIndex = 1;
			// 
			// put_quantity_order_btn
			// 
			this->put_quantity_order_btn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->put_quantity_order_btn->Location = System::Drawing::Point(462, 3);
			this->put_quantity_order_btn->Name = L"put_quantity_order_btn";
			this->put_quantity_order_btn->Size = System::Drawing::Size(149, 24);
			this->put_quantity_order_btn->TabIndex = 3;
			this->put_quantity_order_btn->Text = L"Записать";
			this->put_quantity_order_btn->UseVisualStyleBackColor = true;
			this->put_quantity_order_btn->Click += gcnew System::EventHandler(this, &InventoryForm::put_quantity_order_btn_Click);
			// 
			// create_order_btn
			// 
			this->create_order_btn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->create_order_btn->Location = System::Drawing::Point(309, 3);
			this->create_order_btn->Name = L"create_order_btn";
			this->create_order_btn->Size = System::Drawing::Size(147, 24);
			this->create_order_btn->TabIndex = 2;
			this->create_order_btn->Text = L"Сделать заказ";
			this->create_order_btn->UseVisualStyleBackColor = true;
			this->create_order_btn->Click += gcnew System::EventHandler(this, &InventoryForm::create_order_btn_Click);
			// 
			// find_order_btn
			// 
			this->find_order_btn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->find_order_btn->Location = System::Drawing::Point(156, 3);
			this->find_order_btn->Name = L"find_order_btn";
			this->find_order_btn->Size = System::Drawing::Size(147, 24);
			this->find_order_btn->TabIndex = 1;
			this->find_order_btn->Text = L"Найти";
			this->find_order_btn->UseVisualStyleBackColor = true;
			this->find_order_btn->Click += gcnew System::EventHandler(this, &InventoryForm::find_order_btn_Click);
			// 
			// clear_order_btn
			// 
			this->clear_order_btn->Dock = System::Windows::Forms::DockStyle::Fill;
			this->clear_order_btn->Location = System::Drawing::Point(3, 3);
			this->clear_order_btn->Name = L"clear_order_btn";
			this->clear_order_btn->Size = System::Drawing::Size(147, 24);
			this->clear_order_btn->TabIndex = 0;
			this->clear_order_btn->Text = L"Очистить";
			this->clear_order_btn->UseVisualStyleBackColor = true;
			this->clear_order_btn->Click += gcnew System::EventHandler(this, &InventoryForm::clear_order_btn_Click);
			// 
			// order_dataGrid
			// 
			this->order_dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->order_dataGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->order_dataGrid->Location = System::Drawing::Point(3, 134);
			this->order_dataGrid->Name = L"order_dataGrid";
			this->order_dataGrid->Size = System::Drawing::Size(614, 236);
			this->order_dataGrid->TabIndex = 2;
			this->order_dataGrid->SelectionChanged += gcnew System::EventHandler(this, &InventoryForm::order_dataGrid_SelectionChanged);
			// 
			// history_tabPage
			// 
			this->history_tabPage->Controls->Add(this->order_history_dataGrid);
			this->history_tabPage->Location = System::Drawing::Point(4, 22);
			this->history_tabPage->Name = L"history_tabPage";
			this->history_tabPage->Padding = System::Windows::Forms::Padding(3);
			this->history_tabPage->Size = System::Drawing::Size(626, 379);
			this->history_tabPage->TabIndex = 2;
			this->history_tabPage->Text = L"История заказов";
			this->history_tabPage->UseVisualStyleBackColor = true;
			// 
			// con
			// 
			this->con->ConnectionString = L"Server=localhost;Database=Orders;Trusted_Connection=True;";
			this->con->FireInfoMessageEventOnUserErrors = false;
			// 
			// inventory_dataset
			// 
			this->inventory_dataset->DataSetName = L"NewDataSet";
			// 
			// order_dataset
			// 
			this->order_dataset->DataSetName = L"NewDataSet";
			// 
			// order_history_dataGrid
			// 
			this->order_history_dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->order_history_dataGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->order_history_dataGrid->Location = System::Drawing::Point(3, 3);
			this->order_history_dataGrid->Name = L"order_history_dataGrid";
			this->order_history_dataGrid->Size = System::Drawing::Size(620, 373);
			this->order_history_dataGrid->TabIndex = 0;
			// 
			// InventoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 429);
			this->Controls->Add(this->main_tabContainer);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"InventoryForm";
			this->Text = L"InventoryForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->main_tabContainer->ResumeLayout(false);
			this->inventory_tabPage->ResumeLayout(false);
			this->table_main_inventory->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->groupBox_unnits->ResumeLayout(false);
			this->groupBox_unnits->PerformLayout();
			this->groupBox_caseQuantity->ResumeLayout(false);
			this->groupBox_caseQuantity->PerformLayout();
			this->groupBox_quntity->ResumeLayout(false);
			this->groupBox_quntity->PerformLayout();
			this->category_groupBox->ResumeLayout(false);
			this->category_groupBox->PerformLayout();
			this->groupBox_name->ResumeLayout(false);
			this->groupBox_name->PerformLayout();
			this->groupBox_id->ResumeLayout(false);
			this->groupBox_id->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inventory_datagrid))->EndInit();
			this->order_tabPage->ResumeLayout(false);
			this->order_table->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->groupBox_price_order->ResumeLayout(false);
			this->groupBox_price_order->PerformLayout();
			this->groupBox_supplier_order->ResumeLayout(false);
			this->groupBox_supplier_order->PerformLayout();
			this->groupBox_quantity_order->ResumeLayout(false);
			this->groupBox_quantity_order->PerformLayout();
			this->groupBox_date_order->ResumeLayout(false);
			this->groupBox_date_order->PerformLayout();
			this->groupBox_name_order->ResumeLayout(false);
			this->groupBox_name_order->PerformLayout();
			this->gB_id->ResumeLayout(false);
			this->gB_id->PerformLayout();
			this->tableLayoutPanel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->order_dataGrid))->EndInit();
			this->history_tabPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inventory_dataset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->order_dataset))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->order_history_dataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	Void fill_textboxes_inventory() {
		this->id_textBox->Text = Convert::ToString(this->inventory_datagrid->CurrentRow->Cells["ProductId"]->Value);
		this->name_textBox->Text = Convert::ToString(this->inventory_datagrid->CurrentRow->Cells["ProductName"]->Value);
		this->category_textBox->Text = Convert::ToString(this->inventory_datagrid->CurrentRow->Cells["CategoryName"]->Value);
		this->caseQuantity_textBox->Text = Convert::ToString(this->inventory_datagrid->CurrentRow->Cells["CaseQuantity"]->Value);
		this->units_textBox->Text = Convert::ToString(this->inventory_datagrid->CurrentRow->Cells["Units"]->Value);
		this->quantity_textBox->Text = Convert::ToString(this->inventory_datagrid->CurrentRow->Cells["Quantity"]->Value);
	}

	System::Void set_columns_headers() {
		this->inventory_datagrid->Columns["ProductId"]->HeaderText = L"Код продукции";
		this->inventory_datagrid->Columns["ProductName"]->HeaderText = L"Название";
		this->inventory_datagrid->Columns["CategoryName"]->HeaderText = L"Категория";
		this->inventory_datagrid->Columns["CaseQuantity"]->HeaderText = L"Кейсовость";
		this->inventory_datagrid->Columns["Units"]->HeaderText = L"Ед. измерения";
		this->inventory_datagrid->Columns["Quantity"]->HeaderText = L"Количество";
	}

	Void select_fill_dataGrid() {
		//if(this->con->State == SqlClient::SqlConnection::)
		String^ select_query = 
			"Select pr.ProductId, pr.ProductName, pc.CategoryName, pr.CaseQuantity, pr.Units "  
			"from Products pr "
			"join ProductCategory pc on pr.CategoryId = pc.CategoryId; ";
		
		this->con->Open();
		SqlClient::SqlCommand^ cmd = (gcnew System::Data::SqlClient::SqlCommand(select_query,this->con));
		System::Data::SqlClient::SqlDataAdapter^ adapter = (gcnew System::Data::SqlClient::SqlDataAdapter(cmd));
		adapter->Fill(this->inventory_dataset, "Inventory");
		this->con->Close();
		
		inventory_dataset->Tables["Inventory"]->Columns->Add("Quantity");
		this->inventory_datagrid->DataSource = this->inventory_dataset->Tables["Inventory"];
		
		set_columns_headers();
	}

	/*private: System::Void id_textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ id = id_textBox->Text;
		for (size_t i = 0; i < inventory_datagrid->RowCount-1; ++i) {
			if (id == inventory_datagrid->Rows[i]->Cells["ProductId"]->Value->ToString()) {
				this->inventory_datagrid->Rows[i]->Selected = true;
				this->inventory_datagrid->Rows[i]->;
				break;
			}
		}
	}*/

	private: System::Void inventory_datagrid_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
		fill_textboxes_inventory();
	}

	private: System::Void clear_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->id_textBox->Text = "";
		this->name_textBox->Text = "";
		this->category_textBox->Text = "";
		this->caseQuantity_textBox->Text = "";
		this->units_textBox->Text = "";
		this->quantity_textBox->Text = "";

		select_fill_dataGrid();
	}
	
	System::UInt32 find_row_id(DataGridView^ datagrid,String^ Column, String^ value) {
		for (size_t i = 0; i < datagrid->RowCount - 1; ++i) {
			if (value == datagrid->Rows[i]->Cells[Column]->Value->ToString()) {
				return i;
				break;
			}
		}
	}

	System::Void select_row_by_id(DataGridView^ datagrid, UInt32 row_id) {
		datagrid->CurrentCell = datagrid->Rows[row_id]->Cells[0];
		datagrid->Rows[row_id]->Selected = true;
	}

	private: System::Void find_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ product_id = id_textBox->Text;
		size_t row_id = find_row_id(inventory_datagrid, "ProductId", product_id);
		select_row_by_id(this->inventory_datagrid, row_id);
		/*this->inventory_datagrid->CurrentCell = this->inventory_datagrid->Rows[row_id]->Cells["ProductId"];
		this->inventory_datagrid->Rows[row_id]->Selected = true;*/
	}

	private: System::Void put_quantity_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		/*if (Convert::ToString(this->inventory_datagrid->CurrentRow->Cells["ProductId"]->Value)
				!= this->id_textBox->Text) 
		{
			String^ product_id = id_textBox->Text;
			size_t row_id = find_row_id(inventory_datagrid, "ProductId", product_id);
			select_row_by_id(this->inventory_datagrid, row_id);
		}*/
		this->inventory_datagrid->CurrentRow->Cells["Quantity"]->Value = this->quantity_textBox->Text;
	}

	private: System::Void insert_inventory_products(int inventoryId) {
		String^ insert_query = "insert into InventoryProducts(InventoryId, ProductId, Quantity)"
			"Values(@InventoryId, @ProductId, @Quantity)";
		SqlClient::SqlCommand^ cmd = (gcnew System::Data::SqlClient::SqlCommand(insert_query, this->con));
		cmd->Parameters->Add("@InventoryId", SqlDbType::BigInt);
		cmd->Parameters->Add("@ProductId", SqlDbType::BigInt);
		cmd->Parameters->Add("@Quantity", SqlDbType::BigInt);
		cmd->Prepare();
		for (size_t i = 0; inventory_datagrid->RowCount; ++i) {
			cmd->Parameters["@InventoryId"]->Value = inventoryId;
			cmd->Parameters["@ProductId"]->Value = inventory_datagrid->Rows[i]->Cells["ProductId"];
			cmd->Parameters["@Quantity"]->Value = inventory_datagrid->Rows[i]->Cells["Quantity"];
			cmd->ExecuteNonQuery();
		}
	}

	private: System::Void calc_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ insert_inv_query = "insert into Inventory(InventoryDate) Values (GETDATE());";

		this->con->Open();
		SqlClient::SqlCommand^ cmd = (gcnew System::Data::SqlClient::SqlCommand(insert_inv_query, this->con));
		int inventoryId = (int)cmd->ExecuteScalar();
		insert_inventory_products(inventoryId);
		this->con->Close();

	}

	//
	// Order Tab
	//

	Void fill_textboxes_order() {
		this->id_order_textbox->Text = Convert::ToString(this->order_dataGrid->CurrentRow->Cells["ProductId"]->Value);
		this->name_order_textBox->Text = Convert::ToString(this->order_dataGrid->CurrentRow->Cells["ProductName"]->Value);
		this->supplier_order_textBox->Text = Convert::ToString(this->order_dataGrid->CurrentRow->Cells["SupplierName"]->Value);
		this->price_order_textBox->Text = Convert::ToString(this->order_dataGrid->CurrentRow->Cells["Price"]->Value);
		this->quantity_order_textBox->Text = Convert::ToString(this->order_dataGrid->CurrentRow->Cells["Quantity"]->Value);
	}

	private: System::Void order_dataGrid_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
		fill_textboxes_order();
	}

	System::Void set_order_columns_headers() {
		this->order_dataGrid->Columns["ProductId"]->HeaderText = L"Код продукции";
		this->order_dataGrid->Columns["ProductName"]->HeaderText = L"Название";
		this->order_dataGrid->Columns["SupplierName"]->HeaderText = L"Постащик";
		this->order_dataGrid->Columns["CaseQuantity"]->HeaderText = L"Кейсовость";
		this->order_dataGrid->Columns["Units"]->HeaderText = L"Ед. измерения";
		this->order_dataGrid->Columns["Price"]->HeaderText = L"Цена";
		this->order_dataGrid->Columns["Quantity"]->HeaderText = L"Количество";
	}

	Void select_fill_order_dataGrid() {
		//if(this->con->State == SqlClient::SqlConnection::)
		String^ select_query = 
			"Select Pr.ProductId, Pr.ProductName, Sup.SupplierName, Pr.CaseQuantity, Pr.Units, Pr.Price "  
			"from Products Pr "
			"join ProductSupplier PrSup on Pr.ProductId=PrSup.ProductId "
			"join supplier Sup on PrSup.SupplierId=Sup.SupplierId; ";
		
		this->con->Open();
		SqlClient::SqlCommand^ cmd = (gcnew System::Data::SqlClient::SqlCommand(select_query,this->con));
		System::Data::SqlClient::SqlDataAdapter^ adapter = (gcnew System::Data::SqlClient::SqlDataAdapter(cmd));
		adapter->Fill(this->order_dataset, "Order");
		this->con->Close();
		
		order_dataset->Tables["Order"]->Columns->Add("Quantity");
		this->order_dataGrid->DataSource = this->order_dataset->Tables["Order"];
		
		set_order_columns_headers();
	}


	private: System::Void clear_order_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->id_order_textbox->Text = "";
		this->name_order_textBox->Text = "";
		this->deliveryDate_textBox->Text = "";
		this->supplier_order_textBox->Text = "";
		this->price_order_textBox->Text = "";
		this->quantity_order_textBox->Text = "";

		//select_fill_order_dataGrid();
	}
	private: System::Void find_order_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ product_id = id_order_textbox->Text;
		size_t row_id = find_row_id(order_dataGrid, "ProductId", product_id);
		select_row_by_id(order_dataGrid, row_id);
	}
	private: System::Void put_quantity_order_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->order_dataGrid->CurrentRow->Cells["Quantity"]->Value = this->quantity_order_textBox->Text;
	}

	private: System::Void insert_order_products(int orderId) {
		String^ insert_query = "insert into OrderProducts(OrderId, ProductId, Qunatity) "
			"Values(@OrderId, @ProductId, @Quantity);";
		SqlClient::SqlCommand^ cmd = (gcnew System::Data::SqlClient::SqlCommand(insert_query, this->con));
		cmd->Parameters->Add("@OrderId", SqlDbType::BigInt);
		cmd->Parameters->Add("@ProductId", SqlDbType::BigInt);
		cmd->Parameters->Add("@Quantity", SqlDbType::BigInt);
		cmd->Prepare();
		for (size_t i = 0; order_dataGrid->RowCount; ++i) {
			cmd->Parameters["@OrderId"]->Value = orderId;
			cmd->Parameters["@ProductId"]->Value = order_dataGrid->Rows[i]->Cells["ProductId"];
			cmd->Parameters["@Quantity"]->Value = order_dataGrid->Rows[i]->Cells["Quantity"];
			cmd->ExecuteNonQuery();
		}
	}

	private: System::Void create_order_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ insert_inv_query = "insert into Orders(CreatedDate, DeliveryDate) Values(GETDATE(), @DeliveryDate);";
		String^ delivery_date = deliveryDate_textBox->Text;

		this->con->Open();
		SqlClient::SqlCommand^ cmd = (gcnew System::Data::SqlClient::SqlCommand(insert_inv_query, this->con));
		cmd->Parameters->Add("@DeliveryDate", SqlDbType::Date);
		cmd->Parameters["@DeliveryDate"]->Value = delivery_date;
		int orderId = (int)cmd->ExecuteScalar();
		insert_order_products(orderId);
		select_fill_order_history();
		this->con->Close();
	}

	//
	// Order History
	//
	System::Void set_columns_order_history_headers() {
		this->order_history_dataGrid->Columns["OrderId"]->HeaderText = L"Код заказа";
		this->order_history_dataGrid->Columns["CreatedDate"]->HeaderText = L"Дата создания";
		this->order_history_dataGrid->Columns["DeliveryDate"]->HeaderText = L"Дата доставки";
		this->order_history_dataGrid->Columns["OrderStatus"]->HeaderText = L"Статус заказа";
		this->order_history_dataGrid->Columns["Cost"]->HeaderText = L"Цена";
	}

	private: System::Void select_fill_order_history() {
		this->order_history_dataset->Clear();
		String^ select_query =
			"Select OrderId, CreatedDate, DeliveryDate, OrderStatus, Cost "
			"from Orders ";

		this->con->Open();
		SqlClient::SqlCommand^ cmd = (gcnew System::Data::SqlClient::SqlCommand(select_query, this->con));
		System::Data::SqlClient::SqlDataAdapter^ adapter = (gcnew System::Data::SqlClient::SqlDataAdapter(cmd));
		adapter->Fill(this->order_history_dataset, "OrdersHistory");
		this->con->Close();

		this->order_history_dataGrid->DataSource = this->order_history_dataset->Tables["OrdersHistory"];

		set_columns_order_history_headers();
	}
};
}
