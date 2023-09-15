using System;
using System.Windows.Forms;

namespace GUIExample {
    public partial class MainForm : Form {
        // GUI öğeleri
        private TextBox textBox;
        private Button button;

        public MainForm() {
            InitializeComponent(); // Form bileşenlerini başlat

            // Metin kutusu oluştur
            textBox = new TextBox();
            textBox.Location = new System.Drawing.Point(50, 50);
            textBox.Size = new System.Drawing.Size(200, 20);

            // Düğme oluştur
            button = new Button();
            button.Text = "Tıkla";
            button.Location = new System.Drawing.Point(50, 80);
            button.Click += new EventHandler(button_Click); // Düğme tıklama olayı

            // Metin kutusu ve düğmeyi forma ekle
            this.Controls.Add(textBox);
            this.Controls.Add(button);
        }

        // Düğme tıklandığında çalışacak işlev
        private void button_Click(object sender, EventArgs e) {
            string text = textBox.Text;
            MessageBox.Show("Girilen Metin: " + text, "Sonuç");
        }

        [STAThread]
        static void Main() {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }
    }
}
