// 自动轮播图
class Swiper {
    constructor(settings = {}) {
        console.log(this);
        this.settings = Object.assign({ auto: true }, settings);
        this.$el = this.settings.el;
        this.$imgList = this.$el.find(".banner-img");
        this.$discList = this.$el.find(".banner-disc").children();
        this.$arr = this.$el.find(".banner-arr");
        this.$index = 0;
        this.$discIndex = 0;

        if (this.settings.auto) {
            this.timer = setInterval(() => {
                this.$index++;
                this.$discIndex++;                  
                if (this.$index > this.$imgList.children().length - 1) {
                    this.$index = 1;
                    this.$imgList.css({ left: 0 });
                }
                if (this.$discIndex > this.$imgList.children().length - 2) {
                    this.$discIndex = 0
                }
                this.play()
            }, 2000)
        }

        // this.init();
        this.mouseHandler();
        this.clickHandler()
    }

    // init() {
    //     this.$cloneLi = this.$imgList.children().eq(0).clone(true);
    //     this.$imgList.append(this.$cloneLi);
    //     this.$discList.eq(0).addClass("active");
    // }

    play() {
        this.$imgList.animate({ left: this.$index * -this.$imgList.children().eq(0).width() });
        this.$discList.removeClass("active").eq(this.$discIndex).addClass("active");
    }
    mouseHandler() {
        this.$el.hover(() => {
            clearInterval(this.timer);
        }, () => {
            if (this.settings.auto) {
                this.timer = setInterval(() => {
                    this.$index++;
                    this.$discIndex++;
                    if (this.$index >= this.$imgList.children().length) {
                        this.$index = 1;
                        this.$imgList.css({ left: 0 });
                    }
                    if (this.$discIndex >= this.$imgList.children().length - 1) {
                        this.$discIndex = 0
                    }
                    this.play()
                }, 2000)
            }
        })

        let self=this;
        this.$arr.children().hover(function (e) {
            // e.stopPropagation();
            clearInterval(self.timer);
            $(this).css({ backgroundColor: "rgb(123,123,123)" })
        }, function (e) {
            clearInterval(self.timer);
            $(this).css({ backgroundColor: "transparent" })
        })
    }
    clickHandler() {
        this.$discList.click((e) => {
            this.$index = this.$discIndex = $(e.target).index();
            this.play();
            console.log(this.$imgList.children().length);

        })
        this.$arr.find(".left").click(() => {
            clearInterval(this.timer);
            this.$index--;
            this.$discIndex--;
            if (this.$index < 0) {
                this.$index = this.$imgList.children().length - 2;
                this.$imgList.css({ left: this.$index * -this.$imgList.children().eq(0).width() });
            }
            if (this.$discIndex < 0) {
                this.$discIndex = this.$imgList.children().length - 2;
            }
            this.play();
        })
        this.$arr.find(".right").click(() => {
            clearInterval(this.timer);
            this.$index++;
            this.$discIndex++;
            if (this.$index >= this.$imgList.children().length) {

                this.$index = 1;
                this.$imgList.css({ left: 0 });
            }
            if (this.$discIndex >= this.$imgList.children().length - 1) {
                this.$discIndex = 0
            }
            this.play()
        })
    }
}

