/**
 * H5表单验证 适用所有，当同时存在多个逻辑时 有先后顺序
 * 注意：凡是设置了正则表达式验证的 需在后面指出具体规则以告知用户
 * @author lautin
 * @created 2019-11-22 14:14:20
 * 
 */

class Validate {

    // 初始化验证元素
    constructor(root) {
        // 提取表单中的输入控件
        if (!root.nodeType) root = document.querySelector(root);

        // 将nodeList以及标识符 写入全局对象中
        // Object.assign(this, {
        //     flag: true,
        // }, {
        //     fields: this.extractInputs(root),
        // });
        this.flag = true;
        this.fields = this.extractInputs(root);
    }

    /**
     * 遍历节点 提取输入控件
     * @param {dom}} node
     * @param {nodeList} result 返回DOM集合对象
     */
    extractInputs(node, result = null) {
        let fields = result || [];
        const types = ["text", "password", "file", "number", "range", "search", "email", "url"];

        for (let x = node.firstChild; x != null; x = x.nextSibling) {
            // 如果是元素节点 则检测节点名称并递归
            if (x.nodeType == node.ELEMENT_NODE) {
                switch (x.nodeName.toLowerCase()) {
                    case "input":
                        if (types.includes(x.type)) {
                            fields.push(x); //放入该节点
                        }
                        break;
                    case "select":
                    case "textarea":
                        fields.push(x); //放入该节点
                        break;
                }
                // 继续递归
                this.extractInputs(x, fields);
            }
        }
        return fields;
    }

    /**
     * text验证maxLength和minLength
     * @param {object} state
     * @param {dom} item
     */
    chkText(state, item) {
        let result = '';
        switch (true) {
            case state.tooLong:
                result = `${item.name} 不能超过${item.maxLength}位`;
                break;

            case state.tooShort:
                result = `${item.name} 不能少于${item.minLength}位`;
                break;

            case state.patternMismatch:
                result = item.dataset.message || item.placeholder || `输入不符合要求`;
                break;
        }
        return result;
    }

    /**
     * password验证pattern
     * @param {object} state
     */
    chkPwd(state, item) {
        let result = '';
        if (state.patternMismatch) {
            result = item.dataset.message || `密码输入不符合规则要求`
        }
        return result;
    }

    /**
     * number和range类型 先验证min和max，再验证step
     * @param {object} state
     * @param {dom} item
     */
    chkNumber(state, item) {
        let result = '';
        switch (true) {
            case state.rangeOverflow:
                result = `不能超出${item.max}的上限`;
                break;

            case state.rangeUnderflow:
                result = `不能低于${item.min}的下限`;
                break;

            case state.stepMismatch:
                result = item.dataset.message || `${item.value} 不是合法值，需要以${item.step}递增`;
                break;
        }
        return result;
    }

    /**
     * email和url类型 先验证type 再验证pattern
     * @param {object} state
     * @param {dom} item
     */
    emailAndUrl(state, item) {
        let result = '';
        switch (true) {
            case state.typeMismatch: // 适合number、email、url
                result = item.dataset.message || item.placeholder || `${item.name} 格式不正确`;
                break;

            case state.patternMismatch:
                result = item.dataset.message || item.placeholder || `输入不符合规则要求`;
                break;
        }
        return result;
    }

    /**
     * 执行验证的方法
     */
    validate() {
        
        [...this.fields].reverse().forEach((item) => {
            // 验证通过 则跳过本次循环
            if (item.checkValidity()) return;
            // 返回validityState对象
            let state = item.validity,
                message = '';

            // 首先检测值是否为空
            if (state.valueMissing) {
                message = item.dataset.missing || item.placeholder || `${item.name} 不能为空`;
            } else {
                // 根据类型执行不同验证
                switch (item.type) {
                    case "text":
                    case "search":
                        message = this.chkText(state, item);
                        break;
                    case "password":
                        message = this.chkPwd(state, item);
                        break;
                    case "number":
                    case "range":
                        message = this.chkNumber(state, item);
                        break;
                    case "email":
                    case "url":
                        message = this.emailAndUrl(state, item);
                        break;
                }
            }

            // 未知的类型验证
            if (state.badInput) {
                message = `输入了的值无效`;
            }

            // 设置验证提示信息
            item.setCustomValidity(message);

            if (message) {
                // 手动报告验证的结果 触发元素的focus事件 等待用户输入
                item.reportValidity();
                 
                this.flag = false;
            }

        });

        return this.flag;
    }

    /**
     * 调用执行的静态方法
     * @param {dom} root
     */
    static start(root) {
        const obj = new Validate(root);
        return obj.validate();
    }
}

// export default Validate.start;

