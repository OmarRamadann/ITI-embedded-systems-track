import pyautogui
import webbrowser
import time
t=0
s=0
for i in range(200):
    t+=0.5
    s+=2
    
    webbrowser.register(
    'chrome',
    None,
    webbrowser.BackgroundBrowser("C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe")

    )
    link = 'https://mail.google.com/mail/u/0/?tab=rm&ogbl#inbox'
    pyautogui.click(472,16)
    webbrowser.get('chrome').open_new(link)
    time.sleep(7)
    # pyautogui.hotkey('ctrl','f')
    # pyautogui.typewrite("Search mail")
    # pyautogui.press('enter')
    # pyautogui.press('escape')
    pyautogui.click(953,131)
    time.sleep(3)
    pyautogui.click(446,193)
    time.sleep(1)
    pyautogui.typewrite("linkedin")
    pyautogui.click(907,560)
    time.sleep(2+s)
    # pyautogui.position(277,252)
    # while(pyautogui.position()==(907,560)): 
        # time.sleep(1)
        # pyautogui.position(277,252)
    pyautogui.click(277,252)
    time.sleep(1.5)
    pyautogui.click(429,251)
    time.sleep(8)
    