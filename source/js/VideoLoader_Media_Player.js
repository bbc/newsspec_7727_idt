define(['bump-3'], function ($) {
    return {
        init: function (container, target, settings) {

            var mp = $('#' + container).player({
                product : settings.product,
                playerProfile: settings.playerProfile,
                responsive: settings.responsive,
                autoplay: settings.autoplay,
                overrideHoldingImage: settings.overrideHoldingImage
            });

            mp.load(target);
        }
    };
});