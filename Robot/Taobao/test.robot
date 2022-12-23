*** Settings ***
Library           Selenium2Library

*** Variables ***
@{account}        18015073951    admin    123456    11111111111    333    \ 18015073951    18015073951 \    ￥#%……&
@{password}       yan011017    admin    123456    11111111111    444    \ yan011017    yan011017 \    @*&#￥￥*

*** Test Cases ***
login
    open browser    https://www.taobao.com    edge    options=add_argument("--disable-blink-features=AutomationControlled");add_experimental_option("excludeSwitches",["enable-automation"])
    Click Element    //*[@id="J_SiteNavLogin"]/div[1]/div[1]/a[1]
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Click Button    //*[@id="login-form"]/div[4]/button
    Wait Until Page Contains Element    //*[@id="login-error"]/div    3    error
    sleep    3
    Input Text    fm-login-id    ${account[0]}
    Click Button    //*[@id="login-form"]/div[4]/button
    Wait Until Page Contains Element    //*[@id="login-error"]/div    3    error
    sleep    3
    Clear Element Text    fm-login-id
    Input Text    fm-login-password    ${password[0]}
    Click Button    //*[@id="login-form"]/div[4]/button
    Wait Until Page Contains Element    //*[@id="login-error"]/div    3    error
    sleep    3
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[1]}
    Input Text    fm-login-password    ${password[1]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    Wait Until Page Contains Element    //*[@id="login-error"]/div    3    error
    sleep    3
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[2]}
    Input Text    fm-login-password    ${password[2]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    Wait Until Page Contains Element    //*[@id="login-error"]/div    3    error
    sleep    3
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[3]}
    Input Text    fm-login-password    ${password[3]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    Wait Until Page Contains Element    //*[@id="login-error"]/div    3    error
    sleep    3
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[4]}
    Input Text    fm-login-password    ${password[4]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    Wait Until Page Contains Element    //*[@id="login-error"]/div    3    error
    sleep    3
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[0]}
    Input Text    fm-login-password    ${password[0]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    sleep    3
    Close Browser
    open browser    https://www.taobao.com    edge    options=add_argument("--disable-blink-features=AutomationControlled");add_experimental_option("excludeSwitches",["enable-automation"])
    Click Element    //*[@id="J_SiteNavLogin"]/div[1]/div[1]/a[1]
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[0]}
    Input Text    fm-login-password    ${password[3]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    Wait Until Page Contains Element    //*[@id="login-error"]/div    3    error
    sleep    3
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[4]}
    Input Text    fm-login-password    ${password[0]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    Wait Until Page Contains Element    //*[@id="login-error"]/div    3    error
    sleep    3
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[0]}
    Input Text    fm-login-password    ${password[0]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    sleep    3
    Close Browser
    open browser    https://www.taobao.com    edge    options=add_argument("--disable-blink-features=AutomationControlled");add_experimental_option("excludeSwitches",["enable-automation"])
    Click Element    //*[@id="J_SiteNavLogin"]/div[1]/div[1]/a[1]
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[5]}
    Input Text    fm-login-password    ${password[0]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    sleep    3
    Close Browser
    open browser    https://www.taobao.com    edge    options=add_argument("--disable-blink-features=AutomationControlled");add_experimental_option("excludeSwitches",["enable-automation"])
    Click Element    //*[@id="J_SiteNavLogin"]/div[1]/div[1]/a[1]
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[0]}
    Input Text    fm-login-password    ${password[5]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    sleep    3
    Close Browser
    open browser    https://www.taobao.com    edge    options=add_argument("--disable-blink-features=AutomationControlled");add_experimental_option("excludeSwitches",["enable-automation"])
    Click Element    //*[@id="J_SiteNavLogin"]/div[1]/div[1]/a[1]
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[6]}
    Input Text    fm-login-password    ${password[0]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    sleep    3
    Close Browser
    open browser    https://www.taobao.com    edge    options=add_argument("--disable-blink-features=AutomationControlled");add_experimental_option("excludeSwitches",["enable-automation"])
    Click Element    //*[@id="J_SiteNavLogin"]/div[1]/div[1]/a[1]
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[0]}
    Input Text    fm-login-password    ${password[6]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    sleep    3
    Close Browser
    open browser    https://www.taobao.com    edge    options=add_argument("--disable-blink-features=AutomationControlled");add_experimental_option("excludeSwitches",["enable-automation"])
    Click Element    //*[@id="J_SiteNavLogin"]/div[1]/div[1]/a[1]
    Clear Element Text    fm-login-id
    Clear Element Text    fm-login-password
    Input Text    fm-login-id    ${account[7]}
    Input Text    fm-login-password    ${password[0]}
    Comment    Drag And Drop By Offset    //*[@id="nc_1_n1z"]    100    0
    Click Button    //*[@id="login-form"]/div[4]/button
    Wait Until Page Contains Element    //*[@id="login-error"]/div    3    error
    sleep    3