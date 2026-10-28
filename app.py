from flask import Flask, render_template, jsonify
import subprocess
import os

app = Flask(__name__)

PATHS = {
    "atm": "/app/ATM Aracı/ATM Aracı/ATM Aracı.cpp",
    "hesap": "/app/Hesap Makinesi/Hesap Makinesi/Hesap Makinesi.cpp",
    "tahmin": "/app/Sayı Tahmin Oyunu/Sayı Tahmin Oyunu/Sayı Tahmin Oyunu.cpp"
}

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/run/<project_name>')
def run_project(project_name):
    if project_name not in PATHS:
        return jsonify({"output": "Proje bulunamadi."})
    
    file_path = PATHS[project_name]
    if not os.path.exists(file_path):
        return jsonify({"output": f"Hata: {file_path} dosyasi bulunamadi."})

    try:
        compile_cmd = f'g++ "{file_path}" -o /tmp/prog'
        compilation = subprocess.run(compile_cmd, shell=True, capture_output=True, text=True)
        
        if compilation.returncode != 0:
            return jsonify({"output": f"Derleme Hatasi:\n{compilation.stderr}"})
        
        execution = subprocess.run('/tmp/prog', shell=True, capture_output=True, text=True, timeout=5)
        return jsonify({"output": execution.stdout if execution.stdout else "Kod calisti ama cikti vermedi."})
        
    except subprocess.TimeoutExpired:
        return jsonify({"output": "Hata: Girdi (input) bekleniyor veya zaman asimi."})
    except Exception as e:
        return jsonify({"output": f"Sistemsel Hata: {str(e)}"})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080)
