define(['lib/news_special/bootstrap', 'VideoLoader_Media_Player'], function (news, mediaPlayer) {
        var EmpLayer = function (container, options) {

            var defaults = {
                    width: '100%',
                    height: '100%',
                    type: 'video',
                    product: 'news',
                    playerProfile: 'smp',
                    responsive: true,
                    autoplay: false,
                    overrideHoldingImage: null
                },
                playlistAttribute = options.playlistDataAttribute || 'data-playlist';

            this.initialised = false;
            this.container = container;
            this.target = container.attr(playlistAttribute);
            this.mediaContentId = this.createUniqueId();

            // allow configuration
            this.settings = news.$.extend({}, defaults, options || {});
        };

        EmpLayer.prototype.init = function () {
            if (!this.initialised) {
                this.addEmp();
                this.initialised = true;
            } else {
                this.updateEmp();
            }
        };

        EmpLayer.prototype.addEmp = function () {
            this.container.append('<div id="' + this.mediaContentId + '" class="ns_media_content"></div>');
            this.load(this.target, this.mediaContentId);
        };

        EmpLayer.prototype.updateEmp = function () {
            this.load(this.target, this.mediaContentId);
        };

        EmpLayer.prototype.load = function (target, container) {
            mediaPlayer.init(container, target, this.settings);
        };

        EmpLayer.prototype.createUniqueId = function () {
            return 'video_loader__video--' + new Date().getTime();
        };

        return EmpLayer;
    });