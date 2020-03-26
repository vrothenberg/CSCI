from flask import Flask, render_template, url_for, flash, redirect
from forms import RegistrationForm, LoginForm
app = Flask(__name__)

app.config['SECRET_KEY'] = '07cbf9325d216051fd67104191bde26b'

posts = [
    {
        'author': 'Vince',
        'title': 'Post 1',
        'content': 'First content',
        'date_posted': 'April 20, 2019'
    },
    {
        'author': 'Someone',
        'title': 'Post 2',
        'content': 'Second post stuff',
        'date_posted': 'Dec 31, 3000'
    }
]

@app.route('/')
@app.route('/home')
def home():
    return render_template('home.html', posts=posts)

@app.route("/about")
def about():
	return render_template('about.html', title='About')

@app.route("/register", methods=['GET', 'POST'])
def register():
    form = RegistrationForm()
    if form.validate_on_submit():
        flash(f'Account created for {form.username.data}!', 'success')
        return redirect(url_for('home'))
    return render_template('register.html', title='Register', form=form)

@app.route("/login")
def login():
    return render_template('home.html', posts=posts)
    #form = LoginForm()
    #return render_template('login.html', title='Login', form=form)

if __name__ == '__main__':
    app.run(host="0.0.0.0",debug=True, port=8080)
