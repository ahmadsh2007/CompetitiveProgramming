import requests
import smtplib
import schedule
import time
from datetime import datetime, timedelta
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

# === Your credentials ===
GMAIL_USER = 'shatnawiahmad2007@gmail.com'
GMAIL_PASS = 'bgphgvwlrciqhqyi'
TO_EMAIL = 'shatnawiahmad2007@gmail.com'

# === Tawjihi info ===
SUNUMBER = "84408"
BIRTH_DATE = "2008-08-27"  # Must be in YYYY-MM-DD format

# === Email timing control ===
last_email_time = None
api_opened = False

# === Email sender ===
def send_email(subject, body):
    global last_email_time
    msg = MIMEMultipart()
    msg['From'] = GMAIL_USER
    msg['To'] = TO_EMAIL
    msg['Subject'] = subject
    msg.attach(MIMEText(body, 'plain'))

    try:
        server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
        server.login(GMAIL_USER, GMAIL_PASS)
        server.send_message(msg)
        server.quit()
        last_email_time = datetime.now()
        print(f"[✓] Email sent: {subject}")
    except Exception as e:
        print(f"[✗] Failed to send email: {e}")

def should_send_email():
    global last_email_time
    if last_email_time is None:
        return True
    return datetime.now() - last_email_time >= timedelta(minutes=15)
# === Tawjihi checker ===
def check_tawjihi():
    global api_opened

    url = "https://www.tawjihi.jo/api/TResults"
    payload = {
        "sunumber": SUNUMBER,
        "Birth_Date": BIRTH_DATE
    }
    headers = {
        "Content-Type": "application/json",
        "User-Agent": "Mozilla/5.0",
        "Referer": "https://www.tawjihi.jo/",
        "Origin": "https://www.tawjihi.jo"
    }

    try:
        response = requests.post(url, json=payload, headers=headers, timeout=10, verify=False)
        if response.status_code == 200:
            data = response.json()
            if data and isinstance(data, list):
                averages = {entry['average'] for entry in data if "average" in entry}
                if not api_opened:
                    api_opened = True  # Stop repeating messages
                    if len(averages) == 1:
                        avg = averages.pop()
                        send_email("🎉 Tawjihi Results Available!", f"Your average is: {avg}")
                    else:
                        send_email("⚠️ Tawjihi Results Inconsistent", f"Different averages found: {averages}")
                else:
                    print("[✓] API open, already notified.")
            else:
                if not api_opened:
                    api_opened = True
                    send_email("📣 Tawjihi Portal Open but No Data", "The portal is open, but your data is not available yet.")
        else:
            raise Exception(f"API returned status {response.status_code}")
    except Exception as e:
        print(f"[✗] Still closed or failed: {e}")
        api_opened = False
        if should_send_email():
            send_email("❌ Tawjihi Still Closed", f"The website is still closed or unavailable.\n\nError: {e}")
# === Initial Google Check ===
def test_google_connection():
    print("🔍 Checking Internet Connection (Google)...")
    try:
        response = requests.get("https://www.google.com", timeout=5)
        if response.status_code == 200:
            print("✅ Internet is working.")
            return True
        else:
            print(f"⚠️ Google returned status: {response.status_code}")
            return False
    except Exception as e:
        print(f"❌ Failed to reach Google: {e}")
        return False

# === Main ===
if __name__ == "__main__":
    if not test_google_connection():
        print("💀 Cannot start Tawjihi checker without internet.")
        exit(1)

    print("📡 Starting Tawjihi monitoring every 5 minute...\n")
    schedule.every(5).minutes.do(check_tawjihi)

    while True:
        schedule.run_pending()
        time.sleep(1)