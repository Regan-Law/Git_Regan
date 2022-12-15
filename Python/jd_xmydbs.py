# -*- coding: utf8 -*-
# python >=3.8
#cron: 25 20 * * *
#new Env('小米改步');
#------------
#环境变量说明
#export MI_USER="小米账号"	仅支持手机号，多账号用 # 分隔
#export MI_PWD="小米密码"	多账号用 # 分隔，且与账号一一对应
#export STEP="小米步数"	空或不填则为 18000-25000 之间随机，自定义示例: 18763 或 19000-24000
import requests,time,re,json,random
import os
import sys
cur_path = os.path.abspath(os.path.dirname(__file__))
root_path = os.path.split(cur_path)[0]
sys.path.append(root_path)
import requests
import json
import time
import hmac
import hashlib
import base64
import urllib.parse
from requests.adapters import HTTPAdapter
from urllib3.util import Retry

# 通知服务
BARK = ''                   # bark服务,自行搜索; secrets可填;
SCKEY = ''                  # Server酱的SCKEY; secrets可填
TG_BOT_TOKEN = ''           # tg机器人的TG_BOT_TOKEN; secrets可填1407203283:AAG9rt-6RDaaX0HBLZQq0laNOh898iFYaRQ
TG_USER_ID = ''             # tg机器人的TG_USER_ID; secrets可填 1434078534
TG_API_HOST=''              # tg 代理api
TG_PROXY_IP = ''            # tg机器人的TG_PROXY_IP; secrets可填
TG_PROXY_PORT = ''          # tg机器人的TG_PROXY_PORT; secrets可填
DD_BOT_ACCESS_TOKEN = ''    # 钉钉机器人的DD_BOT_ACCESS_TOKEN; secrets可填
DD_BOT_SECRET = ''          # 钉钉机器人的DD_BOT_SECRET; secrets可填
QQ_SKEY = ''                # qq机器人的QQ_SKEY; secrets可填
QQ_MODE = ''                # qq机器人的QQ_MODE; secrets可填
QYWX_AM = ''                # 企业微信
PUSH_PLUS_TOKEN = ''        # 微信推送Plus+

notify_mode = []

message_info = ''''''

# GitHub action运行需要填写对应的secrets
if "BARK" in os.environ and os.environ["BARK"]:
    BARK = os.environ["BARK"]
if "SCKEY" in os.environ and os.environ["SCKEY"]:
    SCKEY = os.environ["SCKEY"]
if "TG_BOT_TOKEN" in os.environ and os.environ["TG_BOT_TOKEN"] and "TG_USER_ID" in os.environ and os.environ["TG_USER_ID"]:
    TG_BOT_TOKEN = os.environ["TG_BOT_TOKEN"]
    TG_USER_ID = os.environ["TG_USER_ID"]
if "TG_API_HOST" in os.environ and os.environ["TG_API_HOST"]:
    TG_API_HOST = os.environ["TG_API_HOST"]
if "DD_BOT_ACCESS_TOKEN" in os.environ and os.environ["DD_BOT_ACCESS_TOKEN"] and "DD_BOT_SECRET" in os.environ and os.environ["DD_BOT_SECRET"]:
    DD_BOT_ACCESS_TOKEN = os.environ["DD_BOT_ACCESS_TOKEN"]
    DD_BOT_SECRET = os.environ["DD_BOT_SECRET"]
if "QQ_SKEY" in os.environ and os.environ["QQ_SKEY"] and "QQ_MODE" in os.environ and os.environ["QQ_MODE"]:
    QQ_SKEY = os.environ["QQ_SKEY"]
    QQ_MODE = os.environ["QQ_MODE"]
# 获取pushplus+ PUSH_PLUS_TOKEN
if "PUSH_PLUS_TOKEN" in os.environ:
    if len(os.environ["PUSH_PLUS_TOKEN"]) > 1:
        PUSH_PLUS_TOKEN = os.environ["PUSH_PLUS_TOKEN"]
        # print("已获取并使用Env环境 PUSH_PLUS_TOKEN")
# 获取企业微信应用推送 QYWX_AM
if "QYWX_AM" in os.environ:
    if len(os.environ["QYWX_AM"]) > 1:
        QYWX_AM = os.environ["QYWX_AM"]
        # print("已获取并使用Env环境 QYWX_AM")

if BARK:
    notify_mode.append('bark')
    # print("BARK 推送打开")
if SCKEY:
    notify_mode.append('sc_key')
    # print("Server酱 推送打开")
if TG_BOT_TOKEN and TG_USER_ID:
    notify_mode.append('telegram_bot')
    # print("Telegram 推送打开")
if DD_BOT_ACCESS_TOKEN and DD_BOT_SECRET:
    notify_mode.append('dingding_bot')
    # print("钉钉机器人 推送打开")
if QQ_SKEY and QQ_MODE:
    notify_mode.append('coolpush_bot')
    # print("QQ机器人 推送打开")

if PUSH_PLUS_TOKEN:
    notify_mode.append('pushplus_bot')
    # print("微信推送Plus机器人 推送打开")
if QYWX_AM:
    notify_mode.append('wecom_app')
    # print("企业微信机器人 推送打开")


def message(str_msg):
    global message_info
    print(str_msg)
    message_info = "{}\n{}".format(message_info, str_msg)
    sys.stdout.flush()

def bark(title, content):
    print("\n")
    if not BARK:
        print("bark服务的bark_token未设置!!\n取消推送")
        return
    print("bark服务启动")
    try:
        response = requests.get(
            f"""https://api.day.app/{BARK}/{title}/{urllib.parse.quote_plus(content)}""").json()
        if response['code'] == 200:
            print('推送成功！')
        else:
            print('推送失败！')
    except:
        print('推送失败！')

def serverJ(title, content):
    print("\n")
    if not SCKEY:
        print("server酱服务的SCKEY未设置!!\n取消推送")
        return
    print("serverJ服务启动")
    data = {
        "text": title,
        "desp": content.replace("\n", "\n\n")
    }
    response = requests.post(f"https://sc.ftqq.com/{SCKEY}.send", data=data).json()
    if response['errno'] == 0:
        print('推送成功！')
    else:
        print('推送失败！')

# tg通知
def telegram_bot(title, content):
    try:
        print("\n")
        bot_token = TG_BOT_TOKEN
        user_id = TG_USER_ID
        if not bot_token or not user_id:
            print("tg服务的bot_token或者user_id未设置!!\n取消推送")
            return
        print("tg服务启动")
        if TG_API_HOST:
            if 'http' in TG_API_HOST:
                url = f"{TG_API_HOST}/bot{TG_BOT_TOKEN}/sendMessage"
            else:
                url = f"https://{TG_API_HOST}/bot{TG_BOT_TOKEN}/sendMessage"
        else:
            url = f"https://api.telegram.org/bot{TG_BOT_TOKEN}/sendMessage"

        headers = {'Content-Type': 'application/x-www-form-urlencoded'}
        payload = {'chat_id': str(TG_USER_ID), 'text': f'{title}\n\n{content}', 'disable_web_page_preview': 'true'}
        proxies = None
        if TG_PROXY_IP and TG_PROXY_PORT:
            proxyStr = "http://{}:{}".format(TG_PROXY_IP, TG_PROXY_PORT)
            proxies = {"http": proxyStr, "https": proxyStr}
        try:
            response = requests.post(url=url, headers=headers, params=payload, proxies=proxies).json()
        except:
            print('推送失败！')
        if response['ok']:
            print('推送成功！')
        else:
            print('推送失败！')
    except Exception as e:
        print(e)

def dingding_bot(title, content):
    timestamp = str(round(time.time() * 1000))  # 时间戳
    secret_enc = DD_BOT_SECRET.encode('utf-8')
    string_to_sign = '{}\n{}'.format(timestamp, DD_BOT_SECRET)
    string_to_sign_enc = string_to_sign.encode('utf-8')
    hmac_code = hmac.new(secret_enc, string_to_sign_enc, digestmod=hashlib.sha256).digest()
    sign = urllib.parse.quote_plus(base64.b64encode(hmac_code))  # 签名
    print('开始使用 钉钉机器人 推送消息...', end='')
    url = f'https://oapi.dingtalk.com/robot/send?access_token={DD_BOT_ACCESS_TOKEN}&timestamp={timestamp}&sign={sign}'
    headers = {'Content-Type': 'application/json;charset=utf-8'}
    data = {
        'msgtype': 'text',
        'text': {'content': f'{title}\n\n{content}'}
    }
    response = requests.post(url=url, data=json.dumps(data), headers=headers, timeout=15).json()
    if not response['errcode']:
        print('推送成功！')
    else:
        print('推送失败！')

def coolpush_bot(title, content):
    print("\n")
    if not QQ_SKEY or not QQ_MODE:
        print("qq服务的QQ_SKEY或者QQ_MODE未设置!!\n取消推送")
        return
    print("qq服务启动")
    url=f"https://qmsg.zendee.cn/{QQ_MODE}/{QQ_SKEY}"
    payload = {'msg': f"{title}\n\n{content}".encode('utf-8')}
    response = requests.post(url=url, params=payload).json()
    if response['code'] == 0:
        print('推送成功！')
    else:
        print('推送失败！')
# push推送
def pushplus_bot(title, content):
    try:
        print("\n")
        if not PUSH_PLUS_TOKEN:
            print("PUSHPLUS服务的token未设置!!\n取消推送")
            return
        print("PUSHPLUS服务启动")
        url = 'http://www.pushplus.plus/send'
        data = {
            "token": PUSH_PLUS_TOKEN,
            "title": title,
            "content": content
        }
        body = json.dumps(data).encode(encoding='utf-8')
        headers = {'Content-Type': 'application/json'}
        response = requests.post(url=url, data=body, headers=headers).json()
        if response['code'] == 200:
            print('推送成功！')
        else:
            print('推送失败！')
    except Exception as e:
        print(e)
# 企业微信 APP 推送
def wecom_app(title, content):
    try:
        if not QYWX_AM:
            print("QYWX_AM 并未设置！！\n取消推送")
            return
        QYWX_AM_AY = re.split(',', QYWX_AM)
        if 4 < len(QYWX_AM_AY) > 5:
            print("QYWX_AM 设置错误！！\n取消推送")
            return
        corpid = QYWX_AM_AY[0]
        corpsecret = QYWX_AM_AY[1]
        touser = QYWX_AM_AY[2]
        agentid = QYWX_AM_AY[3]
        try:
            media_id = QYWX_AM_AY[4]
        except:
            media_id = ''
        wx = WeCom(corpid, corpsecret, agentid)
        # 如果没有配置 media_id 默认就以 text 方式发送
        if not media_id:
            message = title + '\n\n' + content
            response = wx.send_text(message, touser)
        else:
            response = wx.send_mpnews(title, content, media_id, touser)
        if response == 'ok':
            print('推送成功！')
        else:
            print('推送失败！错误信息如下：\n', response)
    except Exception as e:
        print(e)

class WeCom:
    def __init__(self, corpid, corpsecret, agentid):
        self.CORPID = corpid
        self.CORPSECRET = corpsecret
        self.AGENTID = agentid

    def get_access_token(self):
        url = 'https://qyapi.weixin.qq.com/cgi-bin/gettoken'
        values = {'corpid': self.CORPID,
                  'corpsecret': self.CORPSECRET,
                  }
        req = requests.post(url, params=values)
        data = json.loads(req.text)
        return data["access_token"]

    def send_text(self, message, touser="@all"):
        send_url = 'https://qyapi.weixin.qq.com/cgi-bin/message/send?access_token=' + self.get_access_token()
        send_values = {
            "touser": touser,
            "msgtype": "text",
            "agentid": self.AGENTID,
            "text": {
                "content": message
            },
            "safe": "0"
        }
        send_msges = (bytes(json.dumps(send_values), 'utf-8'))
        respone = requests.post(send_url, send_msges)
        respone = respone.json()
        return respone["errmsg"]

    def send_mpnews(self, title, message, media_id, touser="@all"):
        send_url = 'https://qyapi.weixin.qq.com/cgi-bin/message/send?access_token=' + self.get_access_token()
        send_values = {
            "touser": touser,
            "msgtype": "mpnews",
            "agentid": self.AGENTID,
            "mpnews": {
                "articles": [
                    {
                        "title": title,
                        "thumb_media_id": media_id,
                        "author": "Author",
                        "content_source_url": "",
                        "content": message.replace('\n', '<br/>'),
                        "digest": message
                    }
                ]
            }
        }
        send_msges = (bytes(json.dumps(send_values), 'utf-8'))
        respone = requests.post(send_url, send_msges)
        respone = respone.json()
        return respone["errmsg"]

def send(title, content):
    """
    使用 bark, telegram bot, dingding bot, serverJ 发送手机推送
    :param title:
    :param content:
    :return:
    """
    ## content += '\n\n开源免费By: https://github.com/curtinlv/JD-Script'
    for i in notify_mode:
        if i == 'bark':
            if BARK:
                bark(title=title, content=content)
            else:
                print('未启用 bark')
            continue
        if i == 'sc_key':
            if SCKEY:
                serverJ(title=title, content=content)
            else:
                print('未启用 Server酱')
            continue
        elif i == 'dingding_bot':
            if DD_BOT_ACCESS_TOKEN and DD_BOT_SECRET:
                dingding_bot(title=title, content=content)
            else:
                print('未启用 钉钉机器人')
            continue
        elif i == 'telegram_bot':
            if TG_BOT_TOKEN and TG_USER_ID:
                telegram_bot(title=title, content=content)
            else:
                print('未启用 telegram机器人')
            continue
        elif i == 'coolpush_bot':
            if QQ_SKEY and QQ_MODE:
                coolpush_bot(title=title, content=content)
            else:
                print('未启用 QQ机器人')
            continue
        elif i == 'pushplus_bot':
            if PUSH_PLUS_TOKEN:
                pushplus_bot(title=title, content=content)
            else:
                print('未启用 PUSHPLUS机器人')
            continue
        elif i == 'wecom_app':
            if QYWX_AM:
                wecom_app(title=title, content=content)
            else:
                print('未启用企业微信应用消息推送')
            continue
        else:
            print('此类推送方式不存在')

now = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
headers = {
        'User-Agent': 'Dalvik/2.1.0 (Linux; U; Android 9; MI 6 MIUI/20.6.18)'
        }
  
#获取登录code
def get_code(location):
    code_pattern = re.compile("(?<=access=).*?(?=&)")
    code = code_pattern.findall(location)[0]
    return code
  
#登录
def login(user,password):
    url1 = "https://api-user.huami.com/registrations/+86" + user + "/tokens"
    headers = {
        "Content-Type":"application/x-www-form-urlencoded;charset=UTF-8",
    "User-Agent":"MiFit/4.6.0 (iPhone; iOS 14.0.1; Scale/2.00)"
        }
    data1 = {
        "client_id":"HuaMi",
        "password":f"{password}",
        "redirect_uri":"https://s3-us-west-2.amazonaws.com/hm-registration/successsignin.html",
        "token":"access"
        }
    r1 = requests.post(url1,data=data1,headers=headers,allow_redirects=False)
    location = r1.headers["Location"]
    try:
        code = get_code(location)
    except:
        return 0,0
    #print("access_code获取成功！")ste
    #print(code)
      
    url2 = "https://account.huami.com/v2/client/login"
    data2 = {
        "app_name":"com.xiaomi.hm.health",
        "app_version":"4.6.0",
        "code":f"{code}",
        "country_code":"CN",
        "device_id":"2C8B4939-0CCD-4E94-8CBA-CB8EA6E613A1",
        "device_model":"phone",
        "grant_type":"access_token",
        "third_name":"huami_phone",
        } 
    r2 = requests.post(url2,data=data2,headers=headers).json()
    login_token = r2["token_info"]["login_token"]
    #print("login_token获取成功！")
    #print(login_token)
    userid = r2["token_info"]["user_id"]
    #print("userid获取成功！")
    #print(userid)
  
    return login_token,userid
  
#主函数
def main(user, passwd, step):
    user = str(user)
    password = str(passwd)
    step = str(step)
    if user == '' or password == '':
        print ("用户名或密码填写有误！")
        return
     
    if step == '':
        print ("已设置为随机步数（20000-29999）")
        step = str(random.randint(20000,29999))
    login_token = 0
    login_token,userid = login(user,password)
    if login_token == 0:
        print("登陆失败！")
        return "login fail!"
  
    t = get_time()
      
    app_token = get_app_token(login_token)
  
    today = time.strftime("%F")
  
    data_json = '%5B%7B%22data_hr%22%3A%22%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F9L%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2FVv%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F0v%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F9e%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F0n%5C%2Fa%5C%2F%5C%2F%5C%2FS%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F0b%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F1FK%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2FR%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F9PTFFpaf9L%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2FR%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F0j%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F9K%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2FOv%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2Fzf%5C%2F%5C%2F%5C%2F86%5C%2Fzr%5C%2FOv88%5C%2Fzf%5C%2FPf%5C%2F%5C%2F%5C%2F0v%5C%2FS%5C%2F8%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2FSf%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2Fz3%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F0r%5C%2FOv%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2FS%5C%2F9L%5C%2Fzb%5C%2FSf9K%5C%2F0v%5C%2FRf9H%5C%2Fzj%5C%2FSf9K%5C%2F0%5C%2F%5C%2FN%5C%2F%5C%2F%5C%2F%5C%2F0D%5C%2FSf83%5C%2Fzr%5C%2FPf9M%5C%2F0v%5C%2FOv9e%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2FS%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2Fzv%5C%2F%5C%2Fz7%5C%2FO%5C%2F83%5C%2Fzv%5C%2FN%5C%2F83%5C%2Fzr%5C%2FN%5C%2F86%5C%2Fz%5C%2F%5C%2FNv83%5C%2Fzn%5C%2FXv84%5C%2Fzr%5C%2FPP84%5C%2Fzj%5C%2FN%5C%2F9e%5C%2Fzr%5C%2FN%5C%2F89%5C%2F03%5C%2FP%5C%2F89%5C%2Fz3%5C%2FQ%5C%2F9N%5C%2F0v%5C%2FTv9C%5C%2F0H%5C%2FOf9D%5C%2Fzz%5C%2FOf88%5C%2Fz%5C%2F%5C%2FPP9A%5C%2Fzr%5C%2FN%5C%2F86%5C%2Fzz%5C%2FNv87%5C%2F0D%5C%2FOv84%5C%2F0v%5C%2FO%5C%2F84%5C%2Fzf%5C%2FMP83%5C%2FzH%5C%2FNv83%5C%2Fzf%5C%2FN%5C%2F84%5C%2Fzf%5C%2FOf82%5C%2Fzf%5C%2FOP83%5C%2Fzb%5C%2FMv81%5C%2FzX%5C%2FR%5C%2F9L%5C%2F0v%5C%2FO%5C%2F9I%5C%2F0T%5C%2FS%5C%2F9A%5C%2Fzn%5C%2FPf89%5C%2Fzn%5C%2FNf9K%5C%2F07%5C%2FN%5C%2F83%5C%2Fzn%5C%2FNv83%5C%2Fzv%5C%2FO%5C%2F9A%5C%2F0H%5C%2FOf8%5C%2F%5C%2Fzj%5C%2FPP83%5C%2Fzj%5C%2FS%5C%2F87%5C%2Fzj%5C%2FNv84%5C%2Fzf%5C%2FOf83%5C%2Fzf%5C%2FOf83%5C%2Fzb%5C%2FNv9L%5C%2Fzj%5C%2FNv82%5C%2Fzb%5C%2FN%5C%2F85%5C%2Fzf%5C%2FN%5C%2F9J%5C%2Fzf%5C%2FNv83%5C%2Fzj%5C%2FNv84%5C%2F0r%5C%2FSv83%5C%2Fzf%5C%2FMP%5C%2F%5C%2F%5C%2Fzb%5C%2FMv82%5C%2Fzb%5C%2FOf85%5C%2Fz7%5C%2FNv8%5C%2F%5C%2F0r%5C%2FS%5C%2F85%5C%2F0H%5C%2FQP9B%5C%2F0D%5C%2FNf89%5C%2Fzj%5C%2FOv83%5C%2Fzv%5C%2FNv8%5C%2F%5C%2F0f%5C%2FSv9O%5C%2F0ZeXv%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F1X%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F9B%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2FTP%5C%2F%5C%2F%5C%2F1b%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F0%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F9N%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2F%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%5C%2Fv7%2B%22%2C%22date%22%3A%222021-08-07%22%2C%22data%22%3A%5B%7B%22start%22%3A0%2C%22stop%22%3A1439%2C%22value%22%3A%22UA8AUBQAUAwAUBoAUAEAYCcAUBkAUB4AUBgAUCAAUAEAUBkAUAwAYAsAYB8AYB0AYBgAYCoAYBgAYB4AUCcAUBsAUB8AUBwAUBIAYBkAYB8AUBoAUBMAUCEAUCIAYBYAUBwAUCAAUBgAUCAAUBcAYBsAYCUAATIPYD0KECQAYDMAYB0AYAsAYCAAYDwAYCIAYB0AYBcAYCQAYB0AYBAAYCMAYAoAYCIAYCEAYCYAYBsAYBUAYAYAYCIAYCMAUB0AUCAAUBYAUCoAUBEAUC8AUB0AUBYAUDMAUDoAUBkAUC0AUBQAUBwAUA0AUBsAUAoAUCEAUBYAUAwAUB4AUAwAUCcAUCYAUCwKYDUAAUUlEC8IYEMAYEgAYDoAYBAAUAMAUBkAWgAAWgAAWgAAWgAAWgAAUAgAWgAAUBAAUAQAUA4AUA8AUAkAUAIAUAYAUAcAUAIAWgAAUAQAUAkAUAEAUBkAUCUAWgAAUAYAUBEAWgAAUBYAWgAAUAYAWgAAWgAAWgAAWgAAUBcAUAcAWgAAUBUAUAoAUAIAWgAAUAQAUAYAUCgAWgAAUAgAWgAAWgAAUAwAWwAAXCMAUBQAWwAAUAIAWgAAWgAAWgAAWgAAWgAAWgAAWgAAWgAAWREAWQIAUAMAWSEAUDoAUDIAUB8AUCEAUC4AXB4AUA4AWgAAUBIAUA8AUBAAUCUAUCIAUAMAUAEAUAsAUAMAUCwAUBYAWgAAWgAAWgAAWgAAWgAAWgAAUAYAWgAAWgAAWgAAUAYAWwAAWgAAUAYAXAQAUAMAUBsAUBcAUCAAWwAAWgAAWgAAWgAAWgAAUBgAUB4AWgAAUAcAUAwAWQIAWQkAUAEAUAIAWgAAUAoAWgAAUAYAUB0AWgAAWgAAUAkAWgAAWSwAUBIAWgAAUC4AWSYAWgAAUAYAUAoAUAkAUAIAUAcAWgAAUAEAUBEAUBgAUBcAWRYAUA0AWSgAUB4AUDQAUBoAXA4AUA8AUBwAUA8AUA4AUA4AWgAAUAIAUCMAWgAAUCwAUBgAUAYAUAAAUAAAUAAAUAAAUAAAUAAAUAAAUAAAUAAAWwAAUAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAeSEAeQ8AcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcBcAcAAAcAAAcCYOcBUAUAAAUAAAUAAAUAAAUAUAUAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcCgAeQAAcAAAcAAAcAAAcAAAcAAAcAYAcAAAcBgAeQAAcAAAcAAAegAAegAAcAAAcAcAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcCkAeQAAcAcAcAAAcAAAcAwAcAAAcAAAcAIAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcCIAeQAAcAAAcAAAcAAAcAAAcAAAeRwAeQAAWgAAUAAAUAAAUAAAUAAAUAAAcAAAcAAAcBoAeScAeQAAegAAcBkAeQAAUAAAUAAAUAAAUAAAUAAAUAAAcAAAcAAAcAAAcAAAcAAAcAAAegAAegAAcAAAcAAAcBgAeQAAcAAAcAAAcAAAcAAAcAAAcAkAegAAegAAcAcAcAAAcAcAcAAAcAAAcAAAcAAAcA8AeQAAcAAAcAAAeRQAcAwAUAAAUAAAUAAAUAAAUAAAUAAAcAAAcBEAcA0AcAAAWQsAUAAAUAAAUAAAUAAAUAAAcAAAcAoAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAYAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcBYAegAAcAAAcAAAegAAcAcAcAAAcAAAcAAAcAAAcAAAeRkAegAAegAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAEAcAAAcAAAcAAAcAUAcAQAcAAAcBIAeQAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcBsAcAAAcAAAcBcAeQAAUAAAUAAAUAAAUAAAUAAAUBQAcBYAUAAAUAAAUAoAWRYAWTQAWQAAUAAAUAAAUAAAcAAAcAAAcAAAcAAAcAAAcAMAcAAAcAQAcAAAcAAAcAAAcDMAeSIAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcAAAcBQAeQwAcAAAcAAAcAAAcAMAcAAAeSoAcA8AcDMAcAYAeQoAcAwAcFQAcEMAeVIAaTYAbBcNYAsAYBIAYAIAYAIAYBUAYCwAYBMAYDYAYCkAYDcAUCoAUCcAUAUAUBAAWgAAYBoAYBcAYCgAUAMAUAYAUBYAUA4AUBgAUAgAUAgAUAsAUAsAUA4AUAMAUAYAUAQAUBIAASsSUDAAUDAAUBAAYAYAUBAAUAUAUCAAUBoAUCAAUBAAUAoAYAIAUAQAUAgAUCcAUAsAUCIAUCUAUAoAUA4AUB8AUBkAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAAfgAA%22%2C%22tz%22%3A32%2C%22did%22%3A%22DA932FFFFE8816E7%22%2C%22src%22%3A24%7D%5D%2C%22summary%22%3A%22%7B%5C%22v%5C%22%3A6%2C%5C%22slp%5C%22%3A%7B%5C%22st%5C%22%3A1628296479%2C%5C%22ed%5C%22%3A1628296479%2C%5C%22dp%5C%22%3A0%2C%5C%22lt%5C%22%3A0%2C%5C%22wk%5C%22%3A0%2C%5C%22usrSt%5C%22%3A-1440%2C%5C%22usrEd%5C%22%3A-1440%2C%5C%22wc%5C%22%3A0%2C%5C%22is%5C%22%3A0%2C%5C%22lb%5C%22%3A0%2C%5C%22to%5C%22%3A0%2C%5C%22dt%5C%22%3A0%2C%5C%22rhr%5C%22%3A0%2C%5C%22ss%5C%22%3A0%7D%2C%5C%22stp%5C%22%3A%7B%5C%22ttl%5C%22%3A18272%2C%5C%22dis%5C%22%3A10627%2C%5C%22cal%5C%22%3A510%2C%5C%22wk%5C%22%3A41%2C%5C%22rn%5C%22%3A50%2C%5C%22runDist%5C%22%3A7654%2C%5C%22runCal%5C%22%3A397%2C%5C%22stage%5C%22%3A%5B%7B%5C%22start%5C%22%3A327%2C%5C%22stop%5C%22%3A341%2C%5C%22mode%5C%22%3A1%2C%5C%22dis%5C%22%3A481%2C%5C%22cal%5C%22%3A13%2C%5C%22step%5C%22%3A680%7D%2C%7B%5C%22start%5C%22%3A342%2C%5C%22stop%5C%22%3A367%2C%5C%22mode%5C%22%3A3%2C%5C%22dis%5C%22%3A2295%2C%5C%22cal%5C%22%3A95%2C%5C%22step%5C%22%3A2874%7D%2C%7B%5C%22start%5C%22%3A368%2C%5C%22stop%5C%22%3A377%2C%5C%22mode%5C%22%3A4%2C%5C%22dis%5C%22%3A1592%2C%5C%22cal%5C%22%3A88%2C%5C%22step%5C%22%3A1664%7D%2C%7B%5C%22start%5C%22%3A378%2C%5C%22stop%5C%22%3A386%2C%5C%22mode%5C%22%3A3%2C%5C%22dis%5C%22%3A1072%2C%5C%22cal%5C%22%3A51%2C%5C%22step%5C%22%3A1245%7D%2C%7B%5C%22start%5C%22%3A387%2C%5C%22stop%5C%22%3A393%2C%5C%22mode%5C%22%3A4%2C%5C%22dis%5C%22%3A1036%2C%5C%22cal%5C%22%3A57%2C%5C%22step%5C%22%3A1124%7D%2C%7B%5C%22start%5C%22%3A394%2C%5C%22stop%5C%22%3A398%2C%5C%22mode%5C%22%3A3%2C%5C%22dis%5C%22%3A488%2C%5C%22cal%5C%22%3A19%2C%5C%22step%5C%22%3A607%7D%2C%7B%5C%22start%5C%22%3A399%2C%5C%22stop%5C%22%3A414%2C%5C%22mode%5C%22%3A4%2C%5C%22dis%5C%22%3A2220%2C%5C%22cal%5C%22%3A120%2C%5C%22step%5C%22%3A2371%7D%2C%7B%5C%22start%5C%22%3A415%2C%5C%22stop%5C%22%3A427%2C%5C%22mode%5C%22%3A3%2C%5C%22dis%5C%22%3A1268%2C%5C%22cal%5C%22%3A59%2C%5C%22step%5C%22%3A1489%7D%2C%7B%5C%22start%5C%22%3A428%2C%5C%22stop%5C%22%3A433%2C%5C%22mode%5C%22%3A1%2C%5C%22dis%5C%22%3A152%2C%5C%22cal%5C%22%3A4%2C%5C%22step%5C%22%3A238%7D%2C%7B%5C%22start%5C%22%3A434%2C%5C%22stop%5C%22%3A444%2C%5C%22mode%5C%22%3A3%2C%5C%22dis%5C%22%3A2295%2C%5C%22cal%5C%22%3A95%2C%5C%22step%5C%22%3A2874%7D%2C%7B%5C%22start%5C%22%3A445%2C%5C%22stop%5C%22%3A455%2C%5C%22mode%5C%22%3A4%2C%5C%22dis%5C%22%3A1592%2C%5C%22cal%5C%22%3A88%2C%5C%22step%5C%22%3A1664%7D%2C%7B%5C%22start%5C%22%3A456%2C%5C%22stop%5C%22%3A466%2C%5C%22mode%5C%22%3A3%2C%5C%22dis%5C%22%3A1072%2C%5C%22cal%5C%22%3A51%2C%5C%22step%5C%22%3A1245%7D%2C%7B%5C%22start%5C%22%3A467%2C%5C%22stop%5C%22%3A477%2C%5C%22mode%5C%22%3A4%2C%5C%22dis%5C%22%3A1036%2C%5C%22cal%5C%22%3A57%2C%5C%22step%5C%22%3A1124%7D%2C%7B%5C%22start%5C%22%3A478%2C%5C%22stop%5C%22%3A488%2C%5C%22mode%5C%22%3A3%2C%5C%22dis%5C%22%3A488%2C%5C%22cal%5C%22%3A19%2C%5C%22step%5C%22%3A607%7D%2C%7B%5C%22start%5C%22%3A489%2C%5C%22stop%5C%22%3A499%2C%5C%22mode%5C%22%3A4%2C%5C%22dis%5C%22%3A2220%2C%5C%22cal%5C%22%3A120%2C%5C%22step%5C%22%3A2371%7D%2C%7B%5C%22start%5C%22%3A500%2C%5C%22stop%5C%22%3A511%2C%5C%22mode%5C%22%3A3%2C%5C%22dis%5C%22%3A1268%2C%5C%22cal%5C%22%3A59%2C%5C%22step%5C%22%3A1489%7D%2C%7B%5C%22start%5C%22%3A512%2C%5C%22stop%5C%22%3A522%2C%5C%22mode%5C%22%3A1%2C%5C%22dis%5C%22%3A152%2C%5C%22cal%5C%22%3A4%2C%5C%22step%5C%22%3A238%7D%5D%7D%2C%5C%22goal%5C%22%3A8000%2C%5C%22tz%5C%22%3A%5C%2228800%5C%22%7D%22%2C%22source%22%3A24%2C%22type%22%3A0%7D%5D'
  
    finddate = re.compile(r'.*?date%22%3A%22(.*?)%22%2C%22data.*?')
    findstep = re.compile(r'.*?ttl%5C%22%3A(.*?)%2C%5C%22dis.*?')
    data_json = re.sub(finddate.findall(data_json)[0], today, str(data_json))
    data_json = re.sub(findstep.findall(data_json)[0], step, str(data_json))
      
    url = f'https://api-mifit-cn.huami.com/v1/data/band_data.json?&t={t}'
    head = {
        "apptoken": app_token,
        "Content-Type": "application/x-www-form-urlencoded"
        }
      
    data = f'userid={userid}&last_sync_data_time=1597306380&device_type=0&last_deviceid=DA932FFFFE8816E7&data_json={data_json}'
     
    response = requests.post(url, data=data, headers=head).json()
    #print(response)
    result = f"{user[:4]}****{user[-4:]}: [{now}] 修改步数（{step}）"+ response['message']
    print(result)
    return result
   
#获取时间戳
def get_time():
    url = 'http://api.m.taobao.com/rest/api3.do?api=mtop.common.getTimestamp'
    response = requests.get(url,headers=headers).json()
    t = response['data']['t']
    return t
   
#获取app_token
def get_app_token(login_token):
    url = f"https://account-cn.huami.com/v1/client/app_tokens?app_name=com.xiaomi.hm.health&dn=api-user.huami.com%2Capi-mifit.huami.com%2Capp-analytics.huami.com&login_token={login_token}"
    response = requests.get(url,headers=headers).json()
    app_token = response['token_info']['app_token']
    #print("app_token获取成功！")
    #print(app_token)
    return app_token
 
if __name__ ==  "__main__":

    # 用户名（单用户的格式为 13800138000 ，多用户用#隔开，例如13800138000#13800138000#13800138000）
    # user = "18905887776#15325782650#13396780029#17757888031#13587161205"
    # 登录密码（用#隔开，例如123456#123456#123456）
    # passwd = "1234567v#5u3mce3A#1234567v#1234567v#abc123456"
    # 要修改的步数，直接输入想要修改的步数值，留空为随机步数20000至29999之间
    # step = ""

    
    user = os.environ.get('MI_USER')
    passwd = os.environ.get('MI_PWD')
    step = os.environ.get('STEP')


    user_list = user.split('#')
    passwd_list = passwd.split('#')
    if step is None:
        step = ''
        step_array = ''
    else:
        step_array = step.split('-')
 
    if len(user_list) == len(passwd_list):
        push = ''
        for line in range(0,len(user_list)):
            if len(step_array) == 2:
                step = str(random.randint(int(step_array[0]),int(step_array[1])))
            elif str(step) == '0':
                step = ''
            push += main(user_list[line], passwd_list[line], step) + '\n'
        send('小米运动', push)
    else:
        print('用户名和密码数量不对')
        
