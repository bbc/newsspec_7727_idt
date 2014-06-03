<div class="carousel_small_container">

	<nav class="carousel_nav_container carousel_nav_container--small">
		<button class="carousel_nav carousel_nav--prev">&lt;</button>
		<button class="carousel_nav carousel_nav--next">&gt;</button>
	</nav>

	<ul class="carousel_small">

		<%
		_.forEach(panels, function (thumb) {

			thumb = thumb.thumb;
		%>

			<li class="carousel_small__item" style="background: url(<%= obj.pathStatic %>/<%= obj.vocab_dir %><%= thumb.image %>)">
				<a class="carousel_small__item-link" href="#">
					<span class="carousel_small__item-caption">
						<%= thumb.caption %>
					</span>
				</a>
			</li>

		<% }) %>
		
	</ul>
</div>