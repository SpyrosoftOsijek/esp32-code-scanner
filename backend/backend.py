from flask import Flask, render_template, request, redirect, session

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('main.html')



@app.route('/handle_post', methods=['POST'])
def handle_post():
    if request.method == 'POST':
        data = request.form['barcode']
        print(data)
        return '<h1>{output}</h1>'.format(output=data)
    
