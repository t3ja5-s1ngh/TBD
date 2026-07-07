from fastapi import FastAPI
app = FastAPI()

@app.get('/')
def root():
    return {'message':'welcome esc ver1.0'}

@app.get('/status')
def status():
    return {
            'online':True,
            'device':'desk-companion'
            }

